// Problem link: https://codeforces.com/problemset/problem/1176/E
#include <bits/stdc++.h>
#include <unordered_set> 

#define ll long long
using namespace std;
 
void setIO(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const ll INF = 1e9;
int g1, g2;
unordered_set<int> s1, s2;
void dfs(int v, int mother, int idx, const vector<vector<int>>& adj, vector<bool>& vis){
    if(idx % 2 == 0){
        g1++;
        s1.emplace(v);
    }else{
        g2++;
        s2.emplace(v);
    }
    for(int u : adj[v]){
        if(!vis[u]){
            vis[u] = true;
            dfs(u, v, idx + 1, adj, vis);
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("revegetate");
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        g1 = 0, g2 = 0;
        vector<vector<int>> adj(n);
        s1.clear();
        s2.clear();
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> vis(n);
        vis[0] = true;
        dfs(0, 0, 0, adj, vis);
        if(g1 <= g2){
            cout << g1 << '\n';
            for(int i : s1)
                cout << i + 1<< " ";
            cout << '\n';
        }else{
            cout << g2 << '\n';
            for(int i : s2)
                cout << i + 1 << " ";
            cout << '\n';
        }
    }
    return 0;
}