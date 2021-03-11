import sys

n=int(input())
for _ in range(n):
    c=int(input())
    coinlist=list(map(int,sys.stdin.readline().split()))
    money=int(input())

    dp=[0 for i in range(money+1)]
    dp[0]=1
    for i in coinlist:
        for j in range(1,money+1):
            if j-i>=0:
                dp[j]+=dp[j-i]
    print(dp[money])



