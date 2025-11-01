# Problem link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B

import sys
input = sys.stdin.readline

n, s = map(int, input().split())
a = list(map(int, input().split()))

def compute_sum(x):
    return x * (x + 1) // 2

ans = 0
sum = 0
l = 0

for r, val in enumerate(a):
    sum += val
    while sum > s:
        sum -= a[l]
        l += 1
    ans += compute_sum(r - l + 1)

print(ans)


