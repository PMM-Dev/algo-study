#메모리 : 29076 KB 시간 : 68ms
taebo = input()
left = 0
right = 0
lrSwitch = True
for i in range(0,len(taebo)):
    if(lrSwitch and taebo[i] == '@'):
        left+=1
    elif(not lrSwitch and taebo[i] == '@'):
        right+=1

    if(taebo[i] != '@' and taebo[i] != '='):
        lrSwitch = False

print(left,right)
        
