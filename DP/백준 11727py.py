n=int(input())

answer=1
if n<=1:
    print(answer)
else:
    for i in range(1,n):
        if i%2==0:
            answer=(answer*2)-1
        else:
            answer = (answer*2)+1
    print(answer%10007)