n=int(input())
a=0
b=1
answer=a+b

if n<1:
    print(a)
else:
    for i in range(2,n):
        a = b
        b = answer
        answer=a+b
    print(answer)