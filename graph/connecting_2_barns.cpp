// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1159
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
void dfs(int u, int c, vector<int>& v, const vector<vector<int>>& adj){
    v[u] = c;
    for(int i : adj[u]){
        if(v[i] == -1)
            dfs(i, c, v, adj);
    }
    return;
}
ll cost(int a, int b, const vector<vector<int>>& v){
    ll dis = 1e9;
    for(int i : v[a]){
        int idx = lower_bound(v[b].begin(), v[b].end(), i) - v[b].begin();
        if(idx > 0)
            dis = min(dis, (ll)abs(i - v[b][idx-1]));
        if(idx < v[b].size())
            dis = min(dis, (ll)abs(v[b][idx] - i));
    }
    return dis * dis;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("wormsort");
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> node_comp(n, -1);
        int cur_com = 0;
        for(int i=0; i<n; i++){
            if(node_comp[i] == -1){
                dfs(i, cur_com, node_comp, adj);
                ++cur_com;
            }
        }
        if(node_comp[0] == node_comp[n-1]){
            cout << 0 << '\n';
            continue;
        }
        vector<vector<int>> com(cur_com);
        for(int i=0; i<n; i++)
            com[node_comp[i]].push_back(i);
        ll res = cost(node_comp[0], node_comp[n-1], com);
        for(int c=1; c<cur_com; c++){
            ll co = cost(c, node_comp[0], com) + cost(c, node_comp[n-1], com);
            res = min(res, co);
        }
        cout << res << '\n';
    } 
    return 0;
}