function [received_signal, BER] = wireless_voice_transmission(input_file, tx_power_dBm, distance, num_walls, num_reflectors)
% Wireless voice transmission simulation based on IEEE 802.11g standard
%
% Parameters:
% input_file: Path to binary voice file
% tx_power_dBm: Transmit power in dBm
% distance: Distance between transmitter and receiver in meters
% num_walls: Number of walls in the path
% num_reflectors: Number of reflecting surfaces

% Constants for this function
CARRIER_FREQ = 2.4e9;        % IEEE 802.11g standard frequency
BANDWIDTH = 20e6;            % IEEE 802.11g bandwidth
TEMPERATURE = 290;           % Room temperature in Kelvin
BOLTZMANN = 1.38e-23;        % Boltzmann constant

% Convert transmit power from dBm to linear
tx_power = 10^((tx_power_dBm - 30)/10);

try
    % Read binary file
    fid = fopen(input_file, 'rb');
    if fid == -1
        error('Could not open input file');
    end
    voice_data = fread(fid, 'int16');
    fclose(fid);

    % Convert to binary stream
    binary_data = [];
    for i = 1:length(voice_data)
        % Convert to unsigned for proper binary conversion
        if voice_data(i) < 0
            unsigned_val = voice_data(i) + 65536; % 2^16
        else
            unsigned_val = voice_data(i);
        end
        
        % Convert to 16-bit binary string and then to array
        bin_str = dec2bin(unsigned_val, 16);
        binary_data = [binary_data; str2num(bin_str(:))];
    end

    % Ensure even length for QPSK
    if mod(length(binary_data), 2) == 1
        binary_data = [binary_data; 0];
    end

    % QPSK Modulation
    modulated_signal = qpsk_modulate(binary_data);

    % Plot original constellation
    figure(1);
    subplot(2,2,1);
    scatter(real(modulated_signal(1:min(1000,length(modulated_signal)))), ...
            imag(modulated_signal(1:min(1000,length(modulated_signal)))), '.');
    title('Original QPSK Constellation');
    xlabel('In-phase'); ylabel('Quadrature');
    grid on;

    % Channel effects
    received_signal = apply_channel_effects(modulated_signal, tx_power, distance, ...
        num_walls, num_reflectors, CARRIER_FREQ, BANDWIDTH);

    % Plot constellation after channel effects
    subplot(2,2,2);
    scatter(real(received_signal(1:min(1000,length(received_signal)))), ...
            imag(received_signal(1:min(1000,length(received_signal)))), '.');
    title('Constellation after Channel Effects');
    xlabel('In-phase'); ylabel('Quadrature');
    grid on;

    % Add noise
    noisy_signal = add_noise(received_signal, BANDWIDTH, TEMPERATURE, BOLTZMANN);

    % Plot noisy constellation
    subplot(2,2,3);
    scatter(real(noisy_signal(1:min(1000,length(noisy_signal)))), ...
            imag(noisy_signal(1:min(1000,length(noisy_signal)))), '.');
    title('Constellation with Noise');
    xlabel('In-phase'); ylabel('Quadrature');
    grid on;

    % Time domain plots
    figure(2);
    subplot(3,1,1);
    plot(abs(modulated_signal(1:min(1000,length(modulated_signal)))));
    title('Original Signal Magnitude');
    ylabel('Amplitude');
    grid on;

    subplot(3,1,2);
    plot(abs(received_signal(1:min(1000,length(received_signal)))));
    title('Signal after Channel Effects');
    ylabel('Amplitude');
    grid on;

    subplot(3,1,3);
    plot(abs(noisy_signal(1:min(1000,length(noisy_signal)))));
    title('Signal with Noise');
    xlabel('Sample Index');
    ylabel('Amplitude');
    grid on;

    % Calculate SNR
    signal_power = mean(abs(received_signal).^2);
    noise_power = mean(abs(noisy_signal - received_signal).^2);
    SNR_dB = 10*log10(signal_power/noise_power);
    fprintf('Estimated SNR: %.2f dB\n', SNR_dB);

    % Equalization and demodulation
    demodulated_data = qpsk_demodulate(noisy_signal);

    % Calculate BER
    BER = sum(abs(binary_data - demodulated_data(1:length(binary_data))), 'all') / numel(binary_data);
    fprintf('Bit Error Rate: %.4f\n', BER);

    % Convert back to audio samples
    num_samples = floor(length(demodulated_data)/16);
    received_signal = zeros(num_samples, 1);
    
    for i = 1:num_samples
        bits = demodulated_data((i-1)*16 + 1 : min(i*16, length(demodulated_data)));
        if length(bits) == 16
            bin_str = char(bits + '0');
            val = bin2dec(bin_str);
            if val >= 32768 % Convert back to signed
                val = val - 65536;
            end
            received_signal(i) = val;
        end
    end

    % Save transmission metadata
    fs = 44100; % Standard audio sampling rate
    save('transmission_metadata.mat', 'fs', 'SNR_dB', 'BER');
    
catch ME
    % Error handling
    fprintf('Error occurred: %s\n', ME.message);
    rethrow(ME);
end
end

function modulated = qpsk_modulate(binary_data)
% QPSK modulation
num_symbols = floor(length(binary_data)/2);
reshape_data = reshape(binary_data(1:2*num_symbols), 2, [])';
symbol_mapping = [-1-1i, -1+1i, 1-1i, 1+1i]/sqrt(2);
modulated = symbol_mapping(bi2de(reshape_data) + 1);
end

function demodulated = qpsk_demodulate(received_signal)
% QPSK demodulation with phase correction

% Phase correction using pilot symbols (simplified)
phase_error = angle(mean(received_signal));
corrected_signal = received_signal * exp(-1i*phase_error);

% Symbol decision
symbol_mapping = [-1-1i, -1+1i, 1-1i, 1+1i]/sqrt(2);
demodulated = zeros(length(received_signal)*2, 1);

for i = 1:length(received_signal)
    [~, idx] = min(abs(corrected_signal(i) - symbol_mapping));
    bits = de2bi(idx-1, 2, 'left-msb');
    demodulated(2*i-1:2*i) = bits;
end
end

function received = apply_channel_effects(signal, tx_power, distance, num_walls, ...
    num_reflectors, carrier_freq, bandwidth)
% Apply channel effects including path loss, shadowing, and multipath

% Local constants
LIGHT_SPEED = 3e8;          % Speed of light in m/s
WALL_ATTEN_DB = 6;          % Wall attenuation in dB

% Path loss (d^2 model)
wavelength = LIGHT_SPEED/carrier_freq;
path_loss = (wavelength/(4*pi*distance))^2;

% Shadowing (log-normal)
shadowing_std = 8; % Standard deviation in dB
shadowing = 10^(randn(1)*shadowing_std/20);

% Wall losses
wall_loss = 10^(-num_walls*WALL_ATTEN_DB/10);

% Multipath using Rayleigh fading
num_paths = num_reflectors + 1;
delays = sort(rand(1, num_paths)*1e-6); % Random delays up to 1 μs
gains = (randn(1, num_paths) + 1i*randn(1, num_paths))/sqrt(2);
gains(1) = 1; % Direct path

% Apply multipath
received = zeros(size(signal));
for i = 1:num_paths
    delayed_signal = [zeros(floor(delays(i)*bandwidth), 1); ...
        signal(1:end-floor(delays(i)*bandwidth))];
    received = received + gains(i)*delayed_signal;
end

% Combine all effects
received = received * sqrt(tx_power * path_loss * shadowing * wall_loss);
end

function noisy_signal = add_noise(signal, bandwidth, temperature, boltzmann)
% Add thermal and environmental noise

% Local constants
MICROWAVE_NOISE_DBM = -90;   % Environmental noise from microwave ovens

% Thermal noise
noise_power = boltzmann * temperature * bandwidth;
thermal_noise = sqrt(noise_power/2) * (randn(size(signal)) + 1i*randn(size(signal)));

% Environmental noise (e.g., microwave oven interference)
env_noise_power = 10^((MICROWAVE_NOISE_DBM - 30)/10);
env_noise = sqrt(env_noise_power/2) * (randn(size(signal)) + 1i*randn(size(signal)));

% Combined noise
noisy_signal = signal + thermal_noise + env_noise;
end