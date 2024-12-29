% Usage example:
% Transmit binary file
transmit_binary_audio('test_audio.bin', 'received_audio.bin');

% Convert received binary to WAV (specify appropriate sample rate)
binary_to_wav('received_audio.bin', 'received_audio.wav', 44100);