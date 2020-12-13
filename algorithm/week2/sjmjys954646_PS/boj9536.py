#메모리 : 29076 KB 시간 : 76ms
testcase = int(input())
m= {}
for i in range(0,testcase):
    m.clear()
    sound = input()
    splitsound = sound.split(' ')
    while True:
        order = input()
        if order == "what does the fox say?":
            break;
        splitorder = order.split(' ')
        m[splitorder[0]] = splitorder[2]

    for index in m.values():
        while index in splitsound:    
            splitsound.remove(index) 

    for p in splitsound:
        print(p, end = ' ')


        
    

