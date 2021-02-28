n=int(input())

hCount=0
if n<100:
    hCount+=n
else:
    hCount+=99
    if n==1000:
        n=999
    for i in range(111,n+1):
        a=i//100
        b=(i%100)//10
        c=(i%100)-(10*b)

        if a-b == b-c:
            hCount+=1
print(hCount)