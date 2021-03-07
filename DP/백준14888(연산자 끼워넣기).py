import sys

def ccc(index,sum,list):
    if len(list)==0:
        result.append(sum)
        return
    else:
            for j in range(len(list)):
                if list[j]=='+':
                    ccc(index+1, sum+operation[index], list[:j] + list[j + 1:])
                elif list[j]=='-':
                    ccc(index+1, sum-operation[index], list[:j] + list[j + 1:])
                elif list[j]=='*':
                    ccc(index+1, sum*operation[index], list[:j] + list[j + 1:])
                else:
                    if sum>=0:
                        ccc(index+1, sum//operation[index], list[:j] + list[j + 1:])
                    else:
                        ccc(index + 1, -1*(sum*-1//operation[index]), list[:j] + list[j + 1:])


result=[]
n=int(input())
operation=list(map(int,sys.stdin.readline().split()))
n_Operator=list(map(int,sys.stdin.readline().split()))
operator=[]
sum=operation[0]
for i in range(4):
    if i==0:
        for j in range(n_Operator[i]):
            operator.append('+')
    elif i==1:
        for j in range(n_Operator[i]):
            operator.append('-')
    elif i==2:
        for j in range(n_Operator[i]):
            operator.append('*')
    else:
        for j in range(n_Operator[i]):
            operator.append('//')
ccc(1,sum,operator)
print(max(result))
print(min(result))



