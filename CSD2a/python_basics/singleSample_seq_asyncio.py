import simpleaudio as sa
import asyncio

#load a sample.
print("choose your sample!")
print("kick type: 1")
print("flute type: 2")
sampleChoise = input("")
if sampleChoise == "1":
    filename = 'Kick.wav'
if sampleChoise == "2":
    filename = 'fieuw.wav'

#get the playtimes
print('how many times do you want to play the sample?')
playCount = int(input (""))

#define a quarternote in ms according to the bpm
print('the default bpm is 120, do you want to change it? type: yes or no')
wichBpm = input("")
if wichBpm == "yes":
    print("type your favorite bpm!")
    bpmInput = int(input (""))
    quarternote_dur = 60 / bpmInput
if wichBpm == "no":
    bpmInput = 120
    quarternote_dur = 60 / bpmInput
print("bpm=", bpmInput)


#add the note times given in a list in the correct order
print('Select the note times, 1 = 1, 1/2 = 0.5, 1/4 = 0.25')
noteTimes = []
for i in range(playCount):
    noteTimes.append(float(input("")))
print("note times =", noteTimes)

#convert the noteTimes to 16th time stamps
timestamps16 = []
latestVal = 0
for i in noteTimes:
    timestamps16.append(latestVal)
    if i == 0.25:
        latestVal += 1
    elif i == 0.50:
        latestVal += 2
    elif i == 1:
        latestVal += 4
print("timestamps in 16th=", timestamps16)

#get sample
sample = sa.WaveObject.from_wave_file(filename)

#sequence the loop in asked playtimes and notetimes and play the sample
async def seq():
    for noteTime in noteTimes :
        play_obj = sample.play()
        
        if noteTime == 1: 
            await asyncio.sleep(quarternote_dur)
        if noteTime == 0.5: 
            await asyncio.sleep(quarternote_dur/2)
        if noteTime == 0.25: 
            await asyncio.sleep(quarternote_dur/4)
       
        # play_obj.wait_done()
    
asyncio.run(seq())