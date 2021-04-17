n,m = map(int,input().split())
data=[]
for i in range(m):
    row=list(input().split())
    data.append(row)

for i in range(m):
    for j in range(0,n-7):
        for k in range(j,j+8):
            