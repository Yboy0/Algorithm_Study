import sys

t=int(input())

for i in range(t):
    n=int(input())
    ddata1=list(map(int,sys.stdin.readline().split()))
    ddata2=list(map(int,sys.stdin.readline().split()))
    sum=0
    count=0
    while count<2*n:
        max1 = 0
        max2 = 0
        index1 = 0
        index2 = 0
        for i in range(n):
           if ddata1[i]>max1:
               max1=ddata1[i]
               index1=i
           if ddata2[i]>max2:
                max2=ddata2[i]
                index2=i
        if max1>max2:
            sum+=max1
            if ddata1[index1]!=0:
                ddata1[index1]=0
                count+=1
            if index1!=0:
                if ddata1[index1-1]!=0:
                    ddata1[index1-1]=0
                    count += 1
            if index1!=n-1:
                if ddata1[index1 + 1] != 0:
                    ddata1[index1 + 1] = 0
                    count += 1
            if ddata2[index1]!=0:
                ddata2[index1]=0
                count += 1
        else:
            sum+=max2
            if ddata2[index2] != 0:
                ddata2[index2] = 0
                count += 1
            if index2 != 0:
                if ddata2[index2 - 1] != 0:
                    ddata2[index2 - 1] = 0
                    count += 1
            if index2 != n - 1:
                if ddata2[index2 + 1] != 0:
                    ddata2[index2 + 1] = 0
                    count += 1
            if ddata1[index2]!=0:
                ddata1[index2] = 0
                count += 1
print(sum)











