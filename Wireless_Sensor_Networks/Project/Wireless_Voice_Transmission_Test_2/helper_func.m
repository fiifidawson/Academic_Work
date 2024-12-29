% Create a test file
t = 0:1/44100:0.1; % 0.1 seconds of audio
test_signal = int16(32767 * sin(2*pi*1000*t)); % 1kHz tone
fid = fopen('test_audio.bin', 'wb');
fwrite(fid, test_signal, 'int16');
fclose(fid);

% Run transmission
[received_signal, BER] = wireless_voice_transmission('test_audio.bin', 20, 100, 2, 3);

% Save output
received_wav = wireless_receiver(received_signal, 'output.wav');