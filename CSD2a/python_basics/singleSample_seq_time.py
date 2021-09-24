
import simpleaudio as sa
import time

#load a sample
print("choose your sample!")
print("kick type: 1")
print("flute type: 2")
sampleChoise = input("")
if sampleChoise == "1":
    filename = 'Kick.wav'
if sampleChoise == "2":
    filename = 'fieuw.wav'
 
#ask en get the playTimes
print('how many times do you want to play the sample?')
playCount = int(input (""))

#define a quarternote in ms according to the bpm
print('the default bpm is 120, do you want to change it? type: yes or no')
wichBpm = input("")
if wichBpm == "yes":
    print("type your favorite bpm!")
    bpmInput = int(input (""))
    bpm_ms = 60 / bpmInput
if wichBpm == "no":
    bpmInput = 120
    bpm_ms = 60 / bpmInput
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

timeStamps = []
time16thNote = bpm_ms / 4

for i in timestamps16:
    timeStamps.append(i * time16thNote)
print("timesStamps=", timeStamps)


 #get sample
sample = sa.WaveObject.from_wave_file(filename)
time_zero = time.time()

if timeStamps:
    ts = timeStamps.pop(0)

while True:
    now = time.time() - time_zero
    for i in timeStamps:
        if (now >= ts):
             sample.play()
             if timeStamps:
                 ts = timeStamps.pop(0)

    time.sleep(0.001)
    
time.sleep(time16thNote[-1])










#sequence the loop and play the samples
# noteLength = []
# for i in noteTimes:
#     noteLength.append(bpm_ms * i)
# print("notelengte=", noteLength)


# #calculate current

# time_sum = 0

# # while i < (1 + playCount):



    
