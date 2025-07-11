// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=920
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("revegetate");
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, bool>>> adj(n);
    for(int i=0; i<m; i++){
        char type;
        int u, v;
        cin >> type >> u >> v;
        --u, --v;
        adj[u].push_back({v, type == 'S'});
        adj[v].push_back({u, type == 'S'});
    }
    vector<bool> vis(n, false);
    int cnt = 0;
    vector<int> color(n, -1);
    bool ok = true;
    for(int i=0; i<n && ok; i++){
        if(!vis[i]){
            vis[i] = true;
            cnt++;
            queue<pair<int, bool>> q;
            q.push({i, true});
            color[i] = 1;
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(auto u : adj[cur.first]){
                    if(vis[u.first]){
                        bool same = (color[cur.first] == color[u.first]);
                        ok = u.second ? same : !same;
                    }else{
                        vis[u.first] = true;
                        color[u.first] = u.second ? color[cur.first] : !color[cur.first];
                        q.push(u);
                    }
                    if(!ok)
                        break;
                }
                if(!ok)
                    break;
            }
        }
    }
    if(!ok)
        cout << 0 << '\n';
    else{
        cout << 1;
        for(int i=0; i<cnt; i++)
            cout << 0;
        cout << '\n'; 
    }
    return 0;
}