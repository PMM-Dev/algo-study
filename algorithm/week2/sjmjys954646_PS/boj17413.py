#메모리 : 29856 KB 시간 : 112ms
t = input()
tlen = len(t)
index = 0
findWord = True
printlist = []
wordlist = []
while index <= tlen :
    if(index == tlen):        
        wordlist.reverse()
        printlist.append(''.join(wordlist))
        wordlist.clear()
        break
    
    ch = t[index]
    if(ch == "<"):
        if(len(wordlist)!=0):       
            wordlist.reverse()
            printlist.append(''.join(wordlist))
            wordlist.clear()
        wordlist.append(ch)
        findWord = False
    elif(ch == ">"):
        findWord = True
        wordlist.append(ch)
        printlist.append(''.join(wordlist))
        wordlist.clear()
    else:
        if(findWord == False):
            wordlist.append(ch)
            index+=1
            continue

        if(ch == " "):
            wordlist.reverse()
            printlist.append(''.join(wordlist))
            wordlist.clear()
            
        else:
            wordlist.append(ch)

    index+=1

for i in range(0,len(printlist)):
            if(len(printlist[i])==0):
                continue
            if(i>=1 and printlist[i][0]!="<" and printlist[i-1][0] !="<"):
                print(" "+printlist[i], end='')
            else:
                print(printlist[i],end='')
                   
    
        
