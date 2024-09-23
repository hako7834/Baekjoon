n,m,k=map(int,input().split())
test=[]
qks=[]
for _ in range(k):
    f,d = map(int,input().split())
    T = (f-1)+m+1-d
    test.append(T)
print(test.index(min(test))+1)