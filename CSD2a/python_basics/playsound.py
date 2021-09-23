# import simpleaudio as sa

# fc.LeftRightCheck.run()

# import simpleaudio as sa

# print('how many times do you want to play the sample?')
# aantalSpelen = input ("")

# for i in range(1, aantalSpelen + 1) :
#     filename = 'Kick.wav'
#     wave_obj = sa.WaveObject.from_wave_file(filename)
#     play_obj = wave_obj.play()
#     play_obj.wait_done()

import simpleaudio as sa
from simpleaudio.shiny import WaveObject

Howmuch = ["1","2","3","4","5"]
for x in Howmuch:
   play_obj = WaveObject.play()

filename = 'fieuw.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)
play_obj = wave_obj.play()
play_obj.wait_done()


