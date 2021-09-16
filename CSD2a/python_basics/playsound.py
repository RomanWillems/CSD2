# import simpleaudio.functionchecks as fc

#  fc.LeftRightCheck.run()

import simpleaudio as sa

print('how many times do you want to play the sample?')
aantalSpelen = input ("")

for i in range(1, aantalSpelen + 1) :
    filename = 'Kick.wav'
    wave_obj = sa.WaveObject.from_wave_file(filename)
    play_obj = wave_obj.play()
    play_obj.wait_done()


# Howmuch = ["1","2","3","4","5"]
# for x in Howmuch:
#    play_obj = wave_obj.play()

# import simpleaudio as sa

# filename = 'fieuw.wav'
# wave_obj = sa.WaveObject.from_wave_file(filename)
# play_obj = wave_obj.play()
# play_obj.wait_done()


