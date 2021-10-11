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

#make the event to define the timestamps
def event_instrument(instrument,stamps):
    return{
        "instrument": instrument,
        "timestamps": stamps,
        }  

#make the event to define the place of the kick
def event_stamps(time_sig,place):
    return{
        "time_sig": time_sig,
        "place": place,
    }

#get the wished time signatures
print("choose time signature")
print('(4) = 4/4')
print('(3) = 3/4')
print('(5) = 5/4')

#convert the choosen time signature to possible places on the grid
choosen_time_signature = input("")
if choosen_time_signature == "4":
    time_signature = [1,2,3,4,5,6,7,8]
if choosen_time_signature == "3":
    time_signature = [1,2,3,4,5,6]
if choosen_time_signature == "5":
    time_signature = [1,2,3,4,5,6,7,8,9,10]

#make a list of stamps for each individual instrument
stamps = []
def random_place():
    for i in time_signature:
        rand = random.randint(1,100)
        if (rand <= 25):
            stamps.append(event_stamps("stamp_kick",i))
    for i in time_signature:
        rand1 = random.randint(1,100)
        if (rand1 <= 30):
            stamps.append(event_stamps("stamp_snare",i))
    for i in time_signature:
        rand2 = random.randint(1,100)
        if (rand2 <= 70):
            stamps.append(event_stamps("stamp_hihat",i))
            
#convert the individual stamps to timestamps in ms and collect them all together
timeStamps = []
def all_stamps():
    random_place()
    samples = ['Kick','Snare','HiHat']
    for i in stamps:
        if i["time_sig"] == "stamp_kick":
            timeStamps.append(event_instrument(samples[0],i["place"] * bpm))
        if i["time_sig"] == "stamp_snare":
            timeStamps.append(event_instrument(samples[1],i["place"] * bpm))
        if i["time_sig"] == "stamp_hihat":
            timeStamps.append(event_instrument(samples[2],i["place"] * bpm))

#functie aanroepen
all_stamps()

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
            print(",,,,")
            if i["instrument"] == 'Kick':
                Kick.play()
            if i['instrument'] == 'Snare':
                Snare.play()
            if i['instrument'] == 'HiHat':
                HiHat.play()

            #Remove the timestamps when it played.
            timeStamps.remove(i)

            #if the timeStamps are empty, fill it with a copy of the loop so it keeps looping.
            if timeStamps == []:
                print("....")
                time_zero = time.time()
                now = time.time() - time_zero
                timeStamps = copyStamps
                copyStamps = timeStamps.copy()
        