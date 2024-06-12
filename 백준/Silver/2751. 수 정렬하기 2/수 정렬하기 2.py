N = int(input())
upper, number = [], []
for i in range(N):
    num = int(input())
    number.append(num)
number.sort()
for j in number:
    print(j)
    
