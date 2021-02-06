data=[]
sum=0
for i in range(9):
    n=int(input())
    sum+=n
    data.append(n)
try:
    for i in range(len(data)-1):
        for j in range(i+1,len(data)):
                if (data[i]+data[j])==sum-100:
                    del data[i]
                    del data[j-1]
                    raise NotImplementedError
except:
    data.sort()
    for i in data:
        print(i)



