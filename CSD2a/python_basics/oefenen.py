#VRAGEN HOE JE LIJST EEN VOOR EEN OPTELT.


print('how many times do you want to play the sample?')
playCount = int(input (""))

print('Select the note times, 1 = 1, 1/2 = 0.5, 1/4 = 0.25')
noteTimes = []
for i in range(playCount):
    noteTimes.append(float(input("")))
print("note times =", noteTimes)

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
print("timestamps in 16th", timestamps16)
