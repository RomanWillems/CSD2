#VRAGEN HOE JE LIJST EEN VOOR EEN OPTELT


print('how many times do you want to play the sample?')
playCount = int(input (""))

print('Select the note times, 1 = 1, 1/2 = 0.5, 1/4 = 0.25')
noteTimes = []
for i in range(playCount):
    noteTimes.append(float(input("")))
print("note times =", noteTimes)

timestamps16 = []
for i in noteTimes:
    if i == 0.25:
        timestamps16.append(1)
    if i == 0.50:
        timestamps16.append(2)
    if i == 1:
        timestamps16.append(4)
print("timestamps in 16th", timestamps16)
