# Memory : 29076 KB
# Time : 88 ms

s = input()
p = input()

count = 0
i = 0
while i < len(p):
    count += 1

    result = 0
    maxLength = 0
    index = 0
    while True:
        result = s.find(p[i], result)
        if result == -1:
            break

        tempLength = 0
        tempSIndex = result
        tempPIndex = i
        while s[tempSIndex] == p[tempPIndex]:
            tempLength += 1

            if tempSIndex + 1 == len(s) or tempPIndex + 1 == len(p):
                break

            tempSIndex += 1
            tempPIndex += 1

        if maxLength < tempLength:
            index = tempSIndex
            maxLength = tempLength

        result += tempLength

    i += maxLength

print(count)
