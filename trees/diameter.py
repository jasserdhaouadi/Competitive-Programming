# Problem link: https://cses.fi/problemset/task/1131/

import sys
input = sys.stdin.readline

def dfs(u):
    dis = [-1] * n
    stack = []
    dis[u] = 0
    stack.append(u)
    while stack:
        cur = stack.pop()
        for v in adj[cur]:
            if dis[v] == -1:
                dis[v] = dis[cur] + 1
                stack.append(v)
    return dis

n = int(input())
adj =[[] for _ in range(n)]
for _ in range(n-1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

dis = dfs(0)
u = dis.index(max(dis))
dis = dfs(u)
print(max(dis))