# Memory : 29076 LB
# Time : 72 ms

t = int(input())
for i in range(t):
    records = input().split(' ')

    while (True):
        voice = input()
        if voice == "what does the fox say?":
            break

        voices = voice.split(' ')
        records = [value for value in records if value != voices[2]]

    for record in records:
        print(record, end=' ')
