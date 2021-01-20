n,m=map(int,input().split())
data = list(map(int,input().split()))
sum=0
for i in range(0,len(data)-2):
    for j in range(i+1,len(data)-1):
        for k in range(j+1,len(data)):
            cardSum=data[i]+data[j]+data[k]
            if (cardSum <= m) and (cardSum > sum):
                sum=cardSum
print(sum)                
