import time 
import simpleaudio as sa

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

eightNote = bpm_ms / 4
quarterNote = bpm_ms / 2
halfNote = bpm_ms 


Kick = sa.WaveObject.from_wave_file("kit/kick.wav")
Snare = sa.WaveObject.from_wave_file("kit/snare.wav")
HiHat = sa.WaveObject.from_wave_file("kit/hihat.wav")

#Place in grid

placeKick = [0,2,4,6]
placeSnare = [2,6]
placeHiHat = [1,3,5,7]

#convert the place from the kick to timestamps in ms
timeStampsKick = []
for i in placeKick:
    timeStampsKick.append(i * quarterNote)
print("timesStamps Kick=", timeStampsKick)

#convert the place from the snare to timestamps in ms
timeStampsSnare = []
for i in placeSnare:
    timeStampsSnare.append(i * quarterNote)
print("timesStamps Snare=", timeStampsSnare)

#convert the place from the hihat to timestamps in ms
timeStampsHiHat = []
for i in placeHiHat:
    timeStampsHiHat.append(i * quarterNote)
print("timesStamps HiHat=", timeStampsHiHat)


#Make an event for gathering info about the Kick
kick_event = {
    "timeStamps": timeStampsKick,
    "Place": placeKick,
    "instrumentName": "Kick",
    "instrument": Kick
}
snare_event = {
    "timeStamps": timeStampsSnare,
    "place": placeSnare,
    "instrumentName": "Snare",
    "instrument": Snare
}
hihat_event = {
    "timeStamps": timeStampsHiHat,
    "place": placeHiHat,
    "instrumentName": "Hihat",
    "instrument": HiHat
}
#get starting point
time_zero = time.time()

def handle_event(event):
    if event['timeStamps']:
        ts = event['timeStamps'].pop(0)
    
    while True:
        now = time.time() - time_zero
        if (now >= ts):
            print(event['instrumentName'])
            event['instrument'].play()
            #Get the next length en store it in ts again
            if event['timeStamps']:
                ts = event['timeStamps'].pop(0)
            else:
                break
        time.sleep(0.001)
    time.sleep(1)

handle_event(kick_event)
handle_event(snare_event)
handle_event(hihat_event)







