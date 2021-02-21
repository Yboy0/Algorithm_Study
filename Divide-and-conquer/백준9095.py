def ccount(sum,n):
        global count

        if sum == n:
            count+=1
            return
        else:
            if sum+1<=n:
                ccount(sum+1,n)
            if sum+2<=n:
                ccount(sum+2,n)
            if sum+3<=n:
                ccount(sum+3,n)
            if sum>n:
                return

n=int(input())
count=0
ccount(1,n)
ccount(2,n)
ccount(3,n)
print(count)



