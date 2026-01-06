// Problem link: https://cses.fi/problemset/task/1133/

#include <bits/stdc++.h>

#include <unordered_set>

typedef long long ll;
using namespace std;

void dbg(int* x) { cerr << " = " << *x << " "; }

const int INF = 1e9;

vector<vector<int>> adj;
vector<int> subtree;
vector<ll> subtree_distances, total_distances;

void dfs1(int u = 0, int p = -1) {
    for (int& v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subtree[u] += subtree[v];
        subtree_distances[u] += (ll)subtree_distances[v] + subtree[v];
    }
    if (!u) {
        total_distances[u] = subtree_distances[u];
    }
}

void dfs2(int u, int p, int n) {
    for (int& v : adj[u]) {
        if (v == p) continue;
        total_distances[v] = total_distances[u] + n - 2 * subtree[v];
        dfs2(v, u, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    adj.resize(n);
    subtree.resize(n, 1);
    total_distances.resize(n);
    subtree_distances.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    dfs1();
    dfs2(0, -1, n);
    for (ll& i : total_distances) cout << i << " ";
    cout << '\n';
    return 0;
}
