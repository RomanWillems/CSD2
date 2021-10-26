#THE RECAMAN DRUM GENERATOR


import time 
import simpleaudio as sa
import random
from midiutil import MIDIFile

#alot is learnt from my classes at HKU
#site: https://csd.hku.nl/csd2/now/csd2a/
#also the github from Ciska: https://github.com/ciskavriezenga/CSD_21-22

#simple audio: https://simpleaudio.readthedocs.io/en/latest/
#midiutil: https://pypi.org/project/MIDIUtil/

#----------------------------------------------------------------------------------------------#
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

bpm_time = bpm_ms / 2

#----------------------------------------------------------------------------------------------#
#let the user choose the sample for every level, high, mid and low.
Kick = sa.WaveObject.from_wave_file("kit/kick.wav")

#ask for clap or snare
print('choose your samples!')
print('the kick is default')
print('(0) = snare')
print('(1) = clap')
snare_clap = input("")
if snare_clap == "0":
    Snare = sa.WaveObject.from_wave_file("kit/snare.wav")
if snare_clap == "1":
    Snare = sa.WaveObject.from_wave_file("kit/clap.wav")

#ask for closed or open hihat
print('(0) = closed hihat')
print('(1) = open hihat')
hihat_open_closed = input("")
if hihat_open_closed == "0":
    HiHat = sa.WaveObject.from_wave_file("kit/hihat_closed.wav")
if hihat_open_closed == "1":
    HiHat = sa.WaveObject.from_wave_file("kit/hihat_open.wav")

#ask for high or low djembe
print('(0) = high djembe')
print('(1) = low djembe')
djembe_high_low = input("")
if djembe_high_low == "0":
    Djembe = sa.WaveObject.from_wave_file("kit/djembe_high.wav")
if djembe_high_low == "1":
    Djembe = sa.WaveObject.from_wave_file("kit/djembe_low.wav")


#----------------------------------------------------------------------------------------------#
#make the event to define the timestamps, and add the midi values to read it out later on.
def event_instrument(instrument,stamps,stamps_midi,sample,velocity,midi_note,midi_dur):
    return{
        "instrument": instrument,
        "stamps": stamps,
        "stamps_midi": stamps_midi,
        "sample": sample,
        "velocity": velocity,
        "midi_note": midi_note,
        "midi_dur": midi_dur

        }  

#make the event to define the place of the kick, and the place of the midi.
def event_stamps(time_sig,place,place_midi):
    return{
        "time_sig": time_sig,
        "place": place,
        "place_midi": place_midi
        
    }

#----------------------------------------------------------------------------------------------#
#get the wished time signatures
print("choose time signature")
print('(4) = 4/4')
print('(3) = 3/4')
print('(5) = 5/4')
print('(7) = 7/4')

#convert the choosen time signature to possible places on the grid
choosen_time_signature = input("")
if choosen_time_signature == "4":
    #make a list of probabilitys per instrument
    #8 numbers is 4/4
    #probabilitys are produced by Recaman sequence, starting at a point in the sequence.
    probability_kick = [85,31,86,30,87,29,88,28]
    probability_snare = [41,18,42,17,43,16,44,15]
    probability_hihat = [16,44,15,45,14,46,79,113]
    probability_djembe = [43,62,42,63,41,18,42,17]
if choosen_time_signature == "3":
    #6 numbers is 3/4
    probability_kick = [86,30,87,29,88,28]
    probability_snare = [42,17,43,16,44,15]
    probability_hihat = [15,45,14,46,79,113]
    probability_djembe = [42,63,41,18,42,17]
if choosen_time_signature == "5":
    #10 numbers is 5/4
    probability_kick = [84,32,85,31,86,30,87,29,88,28]
    probability_snare = [42,63,41,18,42,17,43,16,44,15]
    probability_hihat = [17,43,16,44,15,45,14,46,79,113]
    probability_djembe = [8,25,43,62,42,63,41,18,42,17]
if choosen_time_signature == "7":
    #10 numbers is 5/4
    probability_kick = [81,35,82,34,83,33,84,32,85,31,86,30,87,29]
    probability_snare = [24,8,25,43,62,42,63,41,18,42,17,43,16,44]
    probability_hihat = [63,41,18,42,17,43,16,44,15,45,14,46,79,113]
    probability_djembe = [22,10,23,9,24,8,25,43,62,42,63,41,18,42]   

#----------------------------------------------------------------------------------------------#
#make a list of stamps for each individual instrument
#stamp is randomly generated accoriding to the probability in the probability lists
#if the random generated number is lower then the probability a stamp is added in the list, stamps.
stamps = []
def random_place():
    for index, item in enumerate(probability_kick):
        rand = random.randint(1,100)
        if (rand <= item):
            stamps.append(event_stamps("stamp_kick",index +1,index))
    for index, item in enumerate(probability_snare):
        rand1 = random.randint(1,100)
        if (rand1 <= item):
            stamps.append(event_stamps("stamp_snare",index +1,index))
    for index, item in enumerate(probability_hihat):
        rand2 = random.randint(1,100)
        if (rand2 <= item):
            stamps.append(event_stamps("stamp_hihat",index +1,index))
    for index, item in enumerate(probability_djembe):
        rand3 = random.randint(1,100)
        if (rand3 <= item):
            stamps.append(event_stamps("stamp_djembe",index +1,index))

#----------------------------------------------------------------------------------------------#
#convert the individual stamps to timestamps in ms and collect them all together
#the time stamp added is accoring to the stamp. it is converted by the bpm_time
#in de list is every info for the midi aswell like velocity,place,duration
#inspired and learnt by JORIS TAKKEN from my class.
timeStamps = []
def all_stamps():
    random_place()
    samples = ['Kick','Snare','HiHat','Djembe']
    for i in stamps:
        if i["time_sig"] == "stamp_kick":
            timeStamps.append(event_instrument(samples[0],i["place"] * bpm_time,i["place_midi"] * bpm_time, Kick, 120, 60, 0.001))
        if i["time_sig"] == "stamp_snare":
            timeStamps.append(event_instrument(samples[1],i["place"] * bpm_time,i["place_midi"] * bpm_time, Snare, 120, 61, 0.001))
        if i["time_sig"] == "stamp_hihat":
            timeStamps.append(event_instrument(samples[2],i["place"] * bpm_time,i["place_midi"] * bpm_time, HiHat, 120, 62, 0.001))
        if i["time_sig"] == "stamp_djembe":
            timeStamps.append(event_instrument(samples[3],i["place"] * bpm_time,i["place_midi"] * bpm_time, Djembe,120, 63, 0.001))
    stamps.clear()
#functie aanroepen
all_stamps()
#copy the timeStamps to make it loop
copyStamps = timeStamps.copy()


#----------------------------------------------------------------------------------------------#
# make a function to make an midi file.
# https://pypi.org/project/MIDIUtil/
# https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2a/theorie/6_writeMIDI
def midi():
    print("midi")

    track = 0 
    timeMidi = 0
    channel = 0
    midi_file = MIDIFile(1) # One track, defaults to format 1 (tempo track
                        # automatically created)
    midi_file.addTempo(track, timeMidi, bpmInput)

    for midi in copyStamps:   
        midi_file.addNote(track, channel, midi['midi_note'], (midi["stamps_midi"] * 2) , 0.1 , 100)

    with open("MidiFile.mid", "wb") as output_file:      
        midi_file.writeFile(output_file)

#----------------------------------------------------------------------------------------------#
#get starting point
time_zero = time.time()


#make a while loop to start the time sequence
play = True
while play:
    #make a counter to detect later on how many times you played the loop, start the counter at 0
    counter = 0
    #start the loop
    while counter < 4:
        now = time.time() - time_zero
        for i in timeStamps:
            #if the time matches a timeStamps, play the sample attached to it (kick,snare or hihat).
            if (now >= i["stamps"]):
                i["sample"].play()
                #Remove the timestamps when it played.
                timeStamps.remove(i)
            
                #if the timeStamps are empty, fill it with a copy of the loop so it keeps looping.
                if timeStamps == []:
                    #count up the counter to check in the while loop when it need to be stopped
                    counter = counter + 1
                    print('loop', counter)
                    if counter < 4:
                        time_zero = time.time()
                        now = time.time() - time_zero
                        timeStamps = copyStamps
                        copyStamps = timeStamps.copy()
                
                    else:
                        print("would you like to play the sample")
                        print("(0) play again")
                        print("(1) print Midi")
                        print("(2) new loop")
                        print("(3) stop")
                        again = input("")
                        
                        #fill the list with the old sequence
                        if again == "0":
                            time_zero = time.time()
                            now = time.time() - time_zero
                            timeStamps = copyStamps
                            copyStamps = timeStamps.copy()
                        
                        #make the midi file by rehancing to the midi function
                        if again == "1":
                            midi()
                            print("kick = midinumber 60")
                            print("snare/clap = midinumber 61")
                            print("hihat= midinumber 62")
                            print("djembe = midinumber 63")
                            play = False

                        #fill the list with new samples
                        if again == "2":
                            timeStamps.clear()
                            copyStamps.clear()
                            all_stamps()
                            copyStamps = timeStamps.copy()
                            time_zero = time.time()
                            now = time.time() - time_zero
                            timeStamps = copyStamps
                            copyStamps = timeStamps.copy()
                        
                        #stop the sequence
                        if again == "3":
                            play = False

                            

