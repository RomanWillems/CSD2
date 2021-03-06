import simpleaudio as sa
import asyncio

#load a sample
filename = 'Kick.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)
 
#Ask the play times
print('how many times do you want to play the sample?')
playCount = int(input (""))

#get Bpm and redefine it to ms
print('What bpm do you want?')
bpmInput = int(input (""))
quarternote_dur = 60 / bpmInput #in ms

#add the note times given in a array in a certain order
print('Select the note times, 1 = 1, 1/2 = 0.5, 1/4 = 0.25')

noteTimes = []
for i in range(playCount):
    noteTimes.append(float(input("")))

print("note times =", noteTimes)

#sequence the loop in asked playtimes and notetimes and play the sample
async def seq():
    for noteTime in noteTimes :
        play_obj = wave_obj.play()
        
        if noteTime == 1: 
            await asyncio.sleep(quarternote_dur)
        if noteTime == 0.5: 
            await asyncio.sleep(quarternote_dur/2)
        if noteTime == 0.25: 
            await asyncio.sleep(quarternote_dur/4)
       
        # play_obj.wait_done()
    
asyncio.run(seq())
