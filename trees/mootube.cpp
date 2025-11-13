// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=788

#include <bits/stdc++.h>
#include <unordered_set>

typedef long long  ll; 
using namespace std;
 
void setIO(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const int INF = 1e9;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("mootube");
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> a(n);
    for(int i=1; i<n; i++){
        int u, v, d;
        cin >> u >> v >> d;
        --u, --v;
        a[u].push_back({v, d});
        a[v].push_back({u, d});
    }
    while(q--){
        int node, k;
        cin >> k >> node;
        --node;
        int ans = 0;
        queue<pair<int, int>> qu;
        qu.push({node, 1e9+1});
        vector<bool> vis(n, false);
        vis[node] = true;
        while(!qu.empty()){
            auto [u, min_rel] = qu.front();
            qu.pop();
            for(auto& [child, rel] : a[u]){
                if(!vis[child] && min(rel, min_rel) >= k){
                    vis[child] = true;
                    ans++;
                    qu.push({child, min(rel, min_rel)});
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
