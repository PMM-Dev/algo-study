s = input()
p = input()
slen = len(s)
plen = len(p)
ans = 0
idx = 0;
while(idx < plen):
    for i in range(plen,0,-1):
        str = p[idx:idx+i]
        if(len(str) > len(s)):
            continue
        
        tt = s.find(str);
        if(tt!=-1):
            idx+=len(str)
            ans+=1
            break

                    
print(ans)
