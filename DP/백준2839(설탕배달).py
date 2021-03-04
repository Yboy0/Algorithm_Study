n=int(input())
answer=-1
a=n//5
while((n-(a*5))%3!=0 and a>=1):
    a-=1
if (n-(a*5))%3==0:
    answer=a+(n-(a*5))//3
print(answer)  

















'''
for i in range(3,n+1):
    if i%5 == 3 or i%5 == 0:
        if i%5 == 3:
            d[i]= (i//5)+1
        else:
            d[i]= (i // 5)
    if i%3 == 5 or i%3 ==0:
        if i % 3 == 5:
            if d[i] > (i // 3) + (i % 3) or d[i]==-1:
                d[i] = (i // 3) + 1
        else:
            if d[i] > (i // 3) or d[i]==-1 :
                d[i]=(i//3)

    if (i%8) == 0 or (i%8)%3 == 0 or (i%8)%5 == 0:
        if (i%8) == 0:
            if d[i] > (i // 8) * 2 or d[i] == -1:
                d[i] = (i // 8) * 2
        elif (i%8)%3 == 0:
            if d[i] > (2*(i//8)) + (i%8)//3 or d[i]==-1:
                d[i] = (2*(i//8)) + (i%8)//3
        else:
            if d[i] > (2*(i//8)) + (i % 8) // 5 or d[i] == -1:
                d[i] = (2*(i//8)) + (i%8)//5
print(d[n])
'''

