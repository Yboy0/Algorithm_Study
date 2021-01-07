import struct
import sys
class Node:
    def __init__(self):
        self.data = None
        self.key = None
        self.left = self.right = None
        self.num = None
    def lappend(self,Node):
        if self.left:
            self.left = None
        self.left=Node
    def rappend(self,Node):
        if self.right:
            self.right=None
        self.right=Node
    def mergeData(self,data1,data2):
            self.data=data1+data2
        
# 허프만 코드를 완성하기 위해 트리를 만들고 각 노드마다 이진코드를 부여하기 위한 클래스
class HufT:
    def __init__(self):
        self.Pnode = Node()
    def mkTree(self,i=0): #노드를 이용해 허프만 트리 만들기
        while (len(strt) > 1):
            node = Node()
            node1 = Node()
            if i == 0:
                b = strt.pop(0)
                node.data = dict[i][1]
                node.key = b
                i += 1
                a = strt.pop(0)
                node1.data = dict[i][1]
                node1.key = a
                i += 1
                self.Pnode.mergeData(node.data,node1.data)
                self.Pnode.lappend(node)  # 작은 쪽
                self.Pnode.rappend(node1)  # 큰 쪽
                strt.append(self.Pnode.data)
            else:
                b = strt.pop(0)
                node.data = dict[i][1]
                node.key = b
                if self.Pnode.data >= node.data:
                    node1.rappend(self.Pnode)
                    node1.lappend(node)
                else:
                    node1.rappend(node)
                    node1.lappend(self.Pnode)
                node1.mergeData(self.Pnode.data,node.data)
                self.Pnode = node1
                i += 1
                del strt[-1]
                strt.append(self.Pnode.data)
        return self.Pnode


    def biNumbering(self,node): # 생성된 허프만 트리의 각 문자당 이진코드 부여
        if node.right or node.left:
            if node.right:
                node.right.num=node.num + '1'
                if node.right.key in dic.keys():
                    dic[node.right.key]=node.right.num
                self.biNumbering(node.right)
            if node.left:
                node.left.num =node.num + '0'
                if node.left.key in dic.keys():
                    dic[node.left.key] = node.left.num
                self.biNumbering(node.left)
            return
        return

    def huf_arch(self): # 각 문자당 부여된 이진코드 기준으로 텍스트파일의 허프만 코드 생성
        arc_str = ''
        for i in strr:
            if i in dic.keys():
                arc_str += dic[i]
        return arc_str


# 문자별 빈도수 체크 함수
def count(string):
    if string in dic:
        dic[string] = dic[string]+1
    else:
        dic[string] = 1

# 허프만 코드를 쪼개서 압축파일에 저장하기 위한 함수
def index_incStr(str):
    list = []
    iii = 8
    ii = 0
    while ii < len(str):
        sss=''
        nnn=0
        if iii > len(str):
            iii = len(str)

        for i in str[ii:iii]:
            sss+=i
        nnn=int('0b'+sss,2)
        iii += 8
        ii += 8
        list.append(nnn)

    return list

# 이진수  앞에 0이 있을때는 정수로 바꾸면 0이 없어지기 때문에 문자열로 앞의 0들을 추가해 주기 위한 함수
def frontZeroch(str,aaa):
    if aaa!=0:
         str=('0'*aaa)+str
         return str
    if len(str) != 8:
        aa = 8 - len(str)
        str = ('0' * aa) + str
    return str
# 문자열로 이뤄진 허프만 코드 숫자로 바꿔서 파일에 저장하기 위한 함
def _to_Bytes(data):
  b = bytearray()
  for i in range(0, len(data), 8):
    b.append(int(data[i:i+8], 2))
  return bytes(b)

# 텍스트 파일에서 받아온 문자열 인코딩하는 클래스
class incoder:
    def __init__(self):
        self.Huf = HufT()
        self.HufStr="" #허프만 코드
        self.Hufbit=None
    def inc(self):
        self.Huf.mkTree()
        pn = self.Huf.Pnode
        pn.num = ''
        self.Huf.biNumbering(pn)
        self.HufStr=self.Huf.huf_arch()

# 압축파일에 저장된 허프만 코드 원본 텍스트 파일 문자열로 디코딩하는 클래스
class decoder:
    def __init__(self,arc_str):
        self.dec_str=''
        self.arc_str=arc_str
    def dec(self):
        check=''
        for i in range(len(self.arc_str)):
            check+=self.arc_str[i]
            for k,v in dic.items():
                if check == v:
                    self.dec_str+=k
                    check=''



### 시작



## 원본 텍스트 파일(text.txt)에서 문자열 읽어 오기
f=open("text.txt",'r')
strr=f.read()
f.close()
print("Text: %s" %(strr))

dic={} # str의 문(key)와 이에 할당된 value(이진코드) 사전
strt=[]
for i in range(len(strr)):
    count(strr[i])
dict=sorted(dic.items(), key=lambda t: t[1]) # 각 문자의 빈도수 체크된 사전
for i in range(len(dic)):
    strt.append(dict[i][0])


## 인코딩으로 압축하고 text.inc 파일에 저장
incoder= incoder()
incoder.inc()
print(dict)
print(dic)
print("Incoding:%s"%(incoder.HufStr))
hst=index_incStr(incoder.HufStr)

f=open('text.inc','wb')
f.write(_to_Bytes(incoder.HufStr))
f.close()

f=open('text.inc','rb')
data=f.read()
f.close()
encode_str=''
for i in range(len(data)):
    if i==len(data)-1:
        aaa=len(incoder.HufStr)-(len(encode_str)+len((format(int(data[i]),'b'))))
        if aaa!=0:
            encode_str+=frontZeroch(format(int(data[i]), 'b'), aaa)
        else:
            encode_str += format(int(data[i]), 'b')

    else:
        encode_str += frontZeroch(format(int(data[i]), 'b'), 0)


## 인코딩파일에서 받아온 숫자를 문자열로 변경해 디코딩하고 text_dec파일에 저장
decoder=decoder(encode_str)
decoder.dec()

print("Decoding:%s" %(decoder.dec_str))

f=open("text_dec.txt", 'w')
f.write(decoder.dec_str)
f=open("text_dec.txt", 'r')
str_dec=f.read()
f.close()




