import sys

def mPay(money,count):
    global fMoney
    if count>=n:
        if count==n:
            if money>fMoney:
                fMoney=money
        return
    else:
        for i in range(len(cList)):
           mPay(money+cList[i],count+(i+1))
fMoney=0
n=int(input())
cList=list((map(int,sys.stdin.readline().split())))
for i in range(len(cList)):
    mPay(cList[i],i+1)
print(fMoney)
