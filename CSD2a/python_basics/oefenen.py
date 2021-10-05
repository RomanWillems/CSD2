import simpleaudio as sa
import Time

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
filename = 'Kick.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)

snare_event = {
    "instrument" : wave_obj
}

def handle_note_event(event):
    print("handle note event function call")
    event["instrument"].play()

handle_note_event(snare_event)

while True:
    print("a")