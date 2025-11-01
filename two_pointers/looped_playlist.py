# Problem link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A

import sys
input = sys.stdin.readline

n, p = map(int, input().split())
a = list(map(int, input().split()))
total_sum = sum(a)
idx, cnt = -1, float('inf')
for l, val in enumerate(a):
    cyc = p // total_sum
    sum = cyc * total_sum
    nbr = cyc * n
    r = l
    while sum < p:
        sum += a[r]
        nbr += 1
        r = (r + 1) % n
    if nbr < cnt:
        cnt = nbr
        idx = l

print(idx + 1, cnt)


