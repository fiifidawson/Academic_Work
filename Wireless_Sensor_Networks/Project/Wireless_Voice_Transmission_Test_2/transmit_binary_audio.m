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
