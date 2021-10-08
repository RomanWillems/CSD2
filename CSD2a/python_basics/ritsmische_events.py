import time 
import simpleaudio as sa
import random


#define a quarternote in ms according to the bpm
print('the default bpm is 120, do you want to change it? type: yes or no')
wichBpm = input("")
if wichBpm == "yes":
    print("type your favorite bpm!")
    bpmInput = int(input(""))
    bpm_ms = 60 / bpmInput
if wichBpm == "no":
    bpmInput = 120
    bpm_ms = 60 / bpmInput
print("bpm=", bpmInput)

bpm = bpm_ms / 2

Kick = sa.WaveObject.from_wave_file("kit/kick.wav")
Snare = sa.WaveObject.from_wave_file("kit/snare.wav")
HiHat = sa.WaveObject.from_wave_file("kit/hihat.wav")   

#maak het event aan om timestamps en instrument te definieren
def event_instrument(instrument,stamps):
    return{
        "instrument": instrument,
        "timestamps": stamps
        }

#Place in grid
placeKick = [1,3,5,7]
placeSnare = [3,7]
placeHiHat = [2,4,6,8]

#convert the gridplace to timestamps in ms and collect them all together
timeStamps = []
for i in placeKick:
    timeStamps.append(event_instrument('kick',i * bpm))
for i in placeSnare:
    timeStamps.append(event_instrument('snare',i * bpm))
for i in placeHiHat:
    timeStamps.append(event_instrument('hihat',i * bpm))

#copy the timeStamps to make it loop
copyStamps = timeStamps.copy()

#get starting point
time_zero = time.time()

#start the loop
while True:
    now = time.time() - time_zero
    for i in timeStamps:
        #if the time matches a timeStamps, play the sample attached to it (kick,snare or hihat)
        if (now >= i["timestamps"]):
            if (i["instrument"]) == 'kick':
                Kick.play()
            if (i['instrument']) == 'snare':
                Snare.play()
            if (i['instrument']) == 'hihat':
                HiHat.play()

            #Remove the timestamps when it played.
            timeStamps.remove(i)

            #if the timeStamps are empty, fill it with a copy of the loop so it keeps looping.
            if timeStamps == []:
                time_zero = time.time()
                now = time.time() - time_zero
                timeStamps = copyStamps
                copyStamps = timeStamps.copy()
        