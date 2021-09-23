#BPM KLOPT NIET

import simpleaudio as sa
import time
 
#ask en get the playTimes
print('how many times do you want to play the sample?')
playCount = int(input (""))

#get the bpm, and convert it to ms
print('What bpm do you want?')
bpmInput = int(input (""))
bpm_ms = 60 / bpmInput #in ms

#ask the notetimes and put them in a list
print('Select the note times, 1 = 1, 1/2 = 0.5, 1/4 = 0.25')

noteTimes = []
for i in range(playCount):
    noteTimes.append(float(input("")))

print("note times =", noteTimes)

#sequence the loop and play the samples
noteLength = []
for i in noteTimes:
    noteLength.append(bpm_ms/i)

#load a sample
filename = 'Kick.wav'
sampleKick = sa.WaveObject.from_wave_file(filename)

#calculate current
time_zero = time.time()
time_sum = 0

# while i < (1 + playCount):
for time_dur in noteTimes:
    time_cur = time.time() - time_zero
    time_dev = time_cur - time_sum
    sampleKick.play()
    time.sleep(time_dur)
    time_sum = time_sum + time_dur
print("time_sum=", time_sum)

    
