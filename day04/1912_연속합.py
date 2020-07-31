n = int(input())
arr = list(map(int, input().split()))

_max = arr[0]
dp = arr[0]

for i in range(1, n+1) :
    dp[i] = max(dp[i-1]+arr[i], arr[i])
    _max = max(dp[i], _max)
print(_max)