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
