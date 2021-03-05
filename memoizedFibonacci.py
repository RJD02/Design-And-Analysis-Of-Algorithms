dp = {}

def fib(n):
    if n in dp.keys():
        return dp[n]
    if n == 0 or n == 1:
        value = n
    else:
        value = fib(n - 1) + fib(n - 2)
    dp[n] = value
    return dp[n]

n = int(input())
print(fib(n))
