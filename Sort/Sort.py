import pandas as pd
import time
import copy

#버블 정렬 
def bubble(list,i):
    for _ in range(len(list)-1):
        for j in range(1,len(list)):
            if list[j][i] < list[j-1][i]:
                temp=list[j-1]
                list[j-1]=list[j]
                list[j]=temp
    return list 

#c.버블 정렬
def bubble_c(list):
    for _ in range(len(list)-1):
      for j in range(1,len(list)):
        i=2 
        if list[j][i] < list[j-1][i]:
             temp=list[j-1]
             list[j-1]=list[j]
             list[j]=temp
        if list[j][i] == list[j-1][i]:
                i=4
                if list[j][i] <list[j-1][i]:
                    temp=list[j-1]
                    list[j-1]=list[j]
                    list[j]=temp     
    return list 

#선택 정렬 
def selection(list,i):
    for j in range(len(list)):
        min=j
        for k in range(j+1,len(list)):
            if list[k][i] <list[min][i]:
                min=k
        temp=list[j]       
        list[j]=list[min]    
        list[min]=temp    
    return list

#c.선택정렬 
def selection_c(list):
    for j in range(len(list)):
        min=j
        for k in range(j+1,len(list)):
            i=2
            if list[k][i] <list[min][i]:
                min=k
            if list[k][i] ==list[min][i]:
                i=4
                if list[k][i] <list[min][i]:
                    min=k   
        temp=list[j]       
        list[j]=list[min]    
        list[min]=temp    
    return list

#삽입 로직
def insert(list,first,last,gap,i):
    k=first+gap
    while k<=last:
        val=k
        pos=k
        temp=list[val]
        while pos>first and list[pos-gap][i]>temp[i]:
            list[pos]=list[pos-gap]
            pos-=gap
        list[pos]=temp
        k+=gap  
  
#쉘 정렬
def shell(list,i):
    gap=len(list)//2
    while gap>0:
        for j in range(gap):
            insert(list,j,len(list)-1,gap,i)
        gap//=2   
    return list

#c.삽입 로직
def insert_c(list,first,last,gap):
    k=first+gap
    while k<=last:
        i=2
        val=k
        pos=k
        temp=list[val]
        while pos>first and list[pos-gap][i]>=temp[i]:
            if list[pos-gap][i]==temp[i]:
                if list[pos-gap][4]>temp[4]:
                    ttemp=list[pos-gap]
                    list[pos-gap]=temp
                    temp=ttemp
                break
            else:    
                list[pos]=list[pos-gap]
                pos-=gap
        list[pos]=temp
        k+=gap  
    
#c.쉘 정렬    
def shell_c(list):
    gap=len(list)//2
    while gap>0:
        for i in range(gap):
            insert_c(list,i,len(list)-1,gap)
        gap//=2   
    return list

#합병 정렬 합치기
def merge_log(left,right,i):
    k=0
    j=0
    result=[]

    while(k<len(left)) & (j<len(right)):
        if left[k][i] < right[j][i]:
            result.append(left[k])
            k+=1
        else:
            result.append(right[j])
            j+=1
    while (k<len(left)):
        result.append(left[k])
        k+=1
    while(j<len(right)):
        result.append(right[j])
        j+=1
    return result    


#합병 정렬 
def merge(list,i):
    if len(list)<2:
        return list
    mid=len(list)//2
    leftlist=list[:mid]
    rightlist=list[mid:]
    left=merge(leftlist,i)
    right=merge(rightlist,i)
    return merge_log(left,right,i)

#c.합병정렬 합치기 
def merge_c_log(left,right):
    k=0
    j=0
    result=[]
    i=2
    while(k<len(left)) & (j<len(right)):
        if left[k][i] < right[j][i]:
            result.append(left[k])
            k+=1
        elif left[k][i] == right[j][i]:
            if left[k][4] < right[j][4]:
                result.append(left[k])
                k+=1
            else:
                result.append(right[j])
                j+=1
        else:
            result.append(right[j])
            j+=1
    while (k<len(left)):
        result.append(left[k])
        k+=1
    while(j<len(right)):
        result.append(right[j])
        j+=1
    return result    

#c.합병정렬 
def merge_c(list):
    if len(list)<2:
        return list
    mid=len(list)//2
    leftlist=list[:mid]
    rightlist=list[mid:]
    left=merge_c(leftlist)
    right=merge_c(rightlist)
    return merge_c_log(left,right)    

#파일 Reading 
## 파일의 내용을 flighters list에 넣는다. 
flighters=[]
data=pd.read_csv("Flighters.csv",names=['name','country','born','statement','num'])
for i in range(0,1310):
    flighters.append(data.loc[i].values)
 

# for i in flighters:
#     print(i)
# print('\n') 

######### 시작  (a b c)
#####정렬 결과 보면 for 문 주석들 풀어야 합니다. 
##각 list들은 처음 시작할때 원본 list를 깊은 복사했습니다.

#a-> 생산년도 기준으로 오름차순 sort 
print('\n')
print("Result a")
## bubble sort
print("<buuble sort>")


bubble_lista=copy.deepcopy(flighters)
start=time.time()
bubble_lista=bubble(bubble_lista,2)
print(time.time()-start)



# for i in bubble_lista:
#     print(i)
# print('\n') 
 
## selection sort
print("<selection sort>")


selection_lista=copy.deepcopy(flighters)
start=time.time()
selection_lista=selection(selection_lista,2)
print(time.time()-start)

# for i in selection_lista:
#     print(i)
# print('\n')   

## shell sort 
print("<shell sort>")


shell_lista=copy.deepcopy(flighters)
start=time.time()
shell_lista=shell(shell_lista,2)
print(time.time()-start)

# for i in shell_lista:
#     print(i)
# print('\n')   

## merge sort 
print("<merge sort>")     


merge_lista=copy.deepcopy(flighters)
start=time.time()
merge_lista=merge(merge_lista,2)
print(time.time()-start)

# for i in merge_lista:
#     print(i)
# print('\n') 


#b-> 생산대수 기준으로 오름차순 sort 
print('\n')
print("Result b")
## bubble sort 
print("<buuble sort>")


bubble_listb=copy.deepcopy(flighters)
start=time.time()
bubble_listb=bubble(bubble_listb,4)
print(time.time()-start)

# for i in bubble_listb:
#     print(i)
# print('\n') 

## selection sort   
print("<selection sort>") 


selection_listb=copy.deepcopy(flighters)
start=time.time()
selection_listb=selection(selection_listb,4)
print(time.time()-start)

# for i in selection_listb:
#     print(i)
# print('\n')  

## shell sort      
print("<shell sort>") 


shell_listb=copy.deepcopy(flighters)
start=time.time()
shell_listb=shell(shell_listb,4)
print(time.time()-start)

# for i in shell_listb:
#     print(i)
# print('\n')   

## merge sort  
print("<merge sort>")    


merge_listb=copy.deepcopy(flighters)
start=time.time()
merge_listb=merge(merge_listb,4)
print(time.time()-start)

# for i in merge_listb:
#     print(i)
# print('\n') 


#c-> 생산년도 기준으로 오름차순 sort한후, 같은 년도의 경우 생산대수 기준으로 오름차순 sort 
print('\n')
print("Result c")
## bubble sort
print("<buuble sort>")

bubble_listc=copy.deepcopy(flighters)

start=time.time()
bubble_listc=bubble_c(bubble_listc)
print(time.time()-start)

# for i in bubble_listc:
#     print(i)
# print('\n') 

## selection sort
print("<selection sort>")


selection_listc=copy.deepcopy(flighters)
start=time.time()
selection_listc=selection_c(selection_listc)
print(time.time()-start)


# for i in selection_listc:
#     print(i) 
# print('\n')   

## shell sort  
print("<shell sort>")


shell_listc=copy.deepcopy(flighters)
start=time.time()
shell_listc=shell_c(shell_listc)
print(time.time()-start)

# for i in shell_listc:
#     print(i) 
# print('\n')  

## merge sort
print("<merge sort>")     


merge_listc=copy.deepcopy(flighters)
start=time.time()
merge_listc=merge_c(merge_listc)
print(time.time()-start)

# for i in merge_listc:
#     print(i)
# print('\n') 
        