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
    #make a list of probabilitys per instrument
    #8 numbers is 4/4
    probability_kick = [100,50,25,50,85,50,25,50]
    probability_snare = [0,25,50,50,80,25,50,50]
    probability_hihat = [25,50,75,50,25,50,75,50]
if choosen_time_signature == "3":
    #6 numbers is 3/4
    probability_kick = [100,50,25,80,25,50]
    probability_snare = [0,25,50,80,30,50]
    probability_hihat = [25,75,50,25,75,50]
if choosen_time_signature == "5":
    #10 numbers is 5/4
    probability_kick = [100,25,50,50,25,100,25,50,50,25]
    probability_snare = [0,25,50,50,20,85,25,50,35,20]
    probability_hihat = [25,50,75,50,35,25,65,75,50,35]

#make a list of stamps for each individual instrument
#stamp is randomly generated accoriding to the probability in the probability lists
stamps = []
def random_place():
    for index, item in enumerate(probability_kick):
        rand = random.randint(1,100)
        if (rand <= item):
            stamps.append(event_stamps("stamp_kick",index))
    for index, item in enumerate(probability_snare):
        rand1 = random.randint(1,100)
        if (rand1 <= item):
            stamps.append(event_stamps("stamp_snare",index))
    for index, item in enumerate(probability_hihat):
        rand2 = random.randint(1,100)
        if (rand2 <= item):
            stamps.append(event_stamps("stamp_hihat",index))
            
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
            if i["instrument"] == 'Kick':
                Kick.play()
                print("kick")
            if i['instrument'] == 'Snare':
                Snare.play()
                print("                         snare")
            if i['instrument'] == 'HiHat':
                HiHat.play()
                print("                                                         hihat")

            #Remove the timestamps when it played.
            timeStamps.remove(i)

            #if the timeStamps are empty, fill it with a copy of the loop so it keeps looping.
            if timeStamps == []:
                print("---------")
                time_zero = time.time()
                now = time.time() - time_zero
                timeStamps = copyStamps
                copyStamps = timeStamps.copy()



                    
                

    
        