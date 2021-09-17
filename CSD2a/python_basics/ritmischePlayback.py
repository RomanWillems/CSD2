import simpleaudio as sa
import time
import asyncio

#kick definieren
filename = 'Kick.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)
 
#Ask the play times
print('how many times do you want to play the sample?')
aantalSpelen = int(input (""))

#Ask the Bpm
print('What bpm do you want?')
bpmInput = int(input (""))
bpm = 60 / bpmInput

#Ask the note times
print('Select the note times, 1 = 1, 1/2 = 0.5, 1/4 = 0.25')

noteTimes = []
for i in range(aantalSpelen):
    noteTimes.append(float(input("")))

print("note times =", noteTimes)

#sequence the loop in asked playtimes and notetimes
async def seq():
    for noteTime in noteTimes :
        play_obj = wave_obj.play()
        
        if noteTime == 1: 
            await asyncio.sleep(bpm)
        if noteTime == 0.5: 
            await asyncio.sleep(bpm/2)
        if noteTime == 0.25: 
            await asyncio.sleep(bpm/4)
       
        # play_obj.wait_done()
    
asyncio.run(seq())
