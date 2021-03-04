import sys
datat=list()
n=int(input())
for i in range(n):
    datat.append(list((map(int,sys.stdin.readline().split()))))
for i in range(1,n):
    for j in range(len(datat[i])):
        if j==0:
            datat[i][j]=datat[i][j]+datat[i-1][j]
        elif j==len(datat[i])-1:
            datat[i][j]=datat[i][j]+datat[i-1][j-1]
        else:
            datat[i][j]=max(datat[i][j]+datat[i-1][j-1],datat[i][j]+datat[i-1][j])
print(max(datat[-1]))