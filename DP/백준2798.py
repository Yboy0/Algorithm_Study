import sys

n,m=map(int,sys.stdin.readline().split())
data=list(map(int,sys.stdin.readline().split()))
max=0
for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            aa=data[i]+data[j]+data[k]
            if aa>max and aa<=m:
                max=aa
print(max)
