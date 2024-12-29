function received_wav = wireless_receiver(received_signal, output_filename)
% Wireless receiver and WAV file converter
%
% Parameters:
% received_signal: Received signal data
% output_filename: Name for output WAV file

% Load transmission metadata
load('transmission_metadata.mat', 'fs', 'SNR_dB', 'BER');

% Apply basic noise reduction
denoised_signal = denoise_audio(received_signal, fs);

% Save as WAV file
audiowrite(output_filename, denoised_signal, fs);
fprintf('File saved as: %s\n', output_filename);
fprintf('Sampling rate: %d Hz\n', fs);
fprintf('Received signal SNR: %.2f dB\n', SNR_dB);

% Plot spectrograms
figure(3);
subplot(2,1,1);
spectrogram(denoised_signal, hamming(256), 128, 256, fs, 'yaxis');
title('Received Signal Spectrogram');

% Plot waveform
subplot(2,1,2);
t = (0:length(denoised_signal)-1)/fs;
plot(t, denoised_signal);
title('Received Waveform');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

received_wav = denoised_signal;
end

% Previous helper functions remain the same