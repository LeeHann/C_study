n = int(input())
arr = list(map(int,input().split()))

_max = min(arr)
sum = 0

for i in range(n) :
    sum = 0
    for j in range(n-i) :
        sum = sum+arr[i+j]
        _max = max(sum, _max)
print(_max)