import simpleaudio as sa

filename = 'Kick.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)

print('how many times do you want to play the sample?')
aantalSpelen = int(input (""))

print('What bpm do you want?')
bpmInput = int(input (""))
bpm = 60 / bpmInput


for a in range(1 + aantalSpelen - 1) :
    play_obj = wave_obj.play()
    play_obj.wait_done()