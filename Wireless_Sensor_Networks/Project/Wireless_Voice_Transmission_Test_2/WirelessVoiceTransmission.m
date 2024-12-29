% Wireless Binary Audio Transmission System (IEEE 802.11n)
classdef WirelessVoiceTransmission
    properties
        % 802.11n parameters
        carrier_freq = 2.4e9;  % 2.4 GHz
        bandwidth = 20e6;      % 20 MHz
        subcarrier_spacing = 312.5e3;
        num_subcarriers = 64;
        cyclic_prefix_length = 16;
        
        % Channel parameters
        tx_power_dBm = 20;
        distance = 50;         % meters
        path_loss_exponent = 2;
        shadowing_std = 4;     % dB
        thermal_noise = -174;  % dBm/Hz
        noise_figure = 10;     % dB
        num_paths = 4;
        microwave_interference = -90; % dBm
    end
    
    methods
        function snr = calculate_snr(obj)
            path_loss = 20*log10(obj.distance) + ...
                       10*obj.path_loss_exponent*log10(obj.distance/1);
            shadowing = obj.shadowing_std * randn(1);
            rx_power = obj.tx_power_dBm - path_loss + shadowing;
            
            noise_power = obj.thermal_noise + ...
                         10*log10(obj.bandwidth) + obj.noise_figure;
            total_noise = 10*log10(10^(noise_power/10) + ...
                                 10^(obj.microwave_interference/10));
            
            snr = rx_power - total_noise;
        end
        
        function [noisy_signal, clean_signal] = transmit(obj, binary_data)
            symbols = obj.binary_to_qpsk(binary_data);
            ofdm_signal = obj.ofdm_modulate(symbols);
            clean_signal = ofdm_signal;
            noisy_signal = obj.apply_channel_effects(ofdm_signal);
        end
        
        function recovered_data = receive(obj, received_signal)
            demod_symbols = obj.ofdm_demodulate(received_signal);
            equalized_symbols = obj.channel_equalization(demod_symbols);
            recovered_data = obj.qpsk_to_binary(equalized_symbols);
        end

        % Convert recovered binary to WAV
        function binary_to_wav(binary_filename, wav_filename, fs)
            % Read binary file
            fid = fopen(binary_filename, 'rb');
            binary_data = fread(fid, 'uint8');
            fclose(fid);
            
            % Convert to audio samples (assuming 16-bit audio)
            audio_int16 = typecast(uint8(binary_data), 'int16');
            audio = double(audio_int16) / 32767;
            
            % Save as WAV
            audiowrite(wav_filename, audio, fs);
        end
        
        % Main script for transmission
        function transmit_binary_audio(input_filename, output_filename)
            % Read binary file
            fid = fopen(input_filename, 'rb');
            binary_data = fread(fid, 'uint8');
            fclose(fid);
            
            % Convert to binary array
            binary_array = zeros(1, length(binary_data) * 8);
            for i = 1:length(binary_data)
                binary_array((i-1)*8 + 1 : i*8) = bitget(binary_data(i), 8:-1:1);
            end
            
            % Initialize wireless system
            wireless_system = WirelessBinaryTransmission();
            
            % Transmit data
            [received_signal, clean_signal] = wireless_system.transmit(binary_array);
            
            % Plot transmission stages
            figure('Name', 'Wireless Transmission Analysis');
            
            % Original signal
            subplot(4,1,1);
            plot(binary_array(1:min(1000, length(binary_array))));
            title('Original Binary Signal');
            xlabel('Bit Index');
            ylabel('Bit Value');
            ylim([-0.2 1.2]);
            grid on;
            
            % Clean OFDM signal
            subplot(4,1,2);
            plot(abs(clean_signal(1:1000)));
            title('OFDM Modulated Signal');
            xlabel('Sample');
            ylabel('Magnitude');
            grid on;
            
            % Noisy signal
            subplot(4,1,3);
            plot(abs(received_signal(1:1000)));
            title('Received Signal (with Channel Effects)');
            xlabel('Sample');
            ylabel('Magnitude');
            grid on;
            
            % Calculate and plot SNR
            snr_values = zeros(1, floor(length(received_signal)/1000));
            for i = 1:length(snr_values)
                segment = received_signal((i-1)*1000 + 1 : i*1000);
                snr_values(i) = 10*log10(var(abs(clean_signal((i-1)*1000 + 1 : i*1000)))) - ...
                                10*log10(var(abs(segment - clean_signal((i-1)*1000 + 1 : i*1000))));
            end
            
            subplot(4,1,4);
            plot(snr_values);
            title('Signal-to-Noise Ratio Over Time');
            xlabel('Time Segment');
            ylabel('SNR (dB)');
            grid on;
            
            % Receive and recover data
            recovered_binary = wireless_system.receive(received_signal);
            
            % Convert back to bytes
            num_bytes = floor(length(recovered_binary)/8);
            recovered_bytes = zeros(num_bytes, 1, 'uint8');
            for i = 1:num_bytes
                byte_bits = recovered_binary((i-1)*8 + 1 : i*8);
                recovered_bytes(i) = sum(byte_bits .* (2.^(7:-1:0)));
            end
            
            % Save recovered binary file
            fid = fopen(output_filename, 'wb');
            fwrite(fid, recovered_bytes, 'uint8');
            fclose(fid);
            
            % Calculate and display bit error rate
            min_len = min(length(binary_array), length(recovered_binary));
            ber = sum(binary_array(1:min_len) ~= recovered_binary(1:min_len)) / min_len;
            fprintf('Bit Error Rate: %.2e\n', ber);
        end

        
        % Helper methods (same as before)
        % ... [previous helper methods remain the same]
    end
end






