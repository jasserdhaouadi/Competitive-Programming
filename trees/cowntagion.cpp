// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1062
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
    // setIO("milkvisits");
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int& i : adj[cur]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
        int n_days;
        if(cur == 0){
            n_days = ceil(log2(adj[cur].size()+1));
            ans += (ll) n_days + adj[cur].size();
        }else{
            n_days = ceil(log2(adj[cur].size()));
            ans += (ll) n_days + adj[cur].size() - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
