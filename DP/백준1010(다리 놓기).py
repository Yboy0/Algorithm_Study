import sys
def bridge(a, b):
    aa=b
    top = 1
    bot = 1
    for i in range(1, a + 1):
        bot *= i
        top *= aa
        aa -= 1

    return top // bot


list=[]
n=int(input())

for _ in range(n):
    a,b=map(int,sys.stdin.readline().split())
    list.append(bridge(a,b))
for i in list:
    print(i)


