// Problem link: https://www.codechef.com/INOIPRAC/problems/AMONGUS2
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
    int t;
    cin >> t;
    while(t--){
        int n, qu;
        cin >> n >> qu;
        vector<vector<pair<bool, pair<int, int>>>> adj(n);
        for(int i=0; i<qu; i++){
            int type, a, b;
            cin >> type >> a >> b;
            --type, --a, --b;
            adj[a].push_back({type, {a, b}});
            adj[b].push_back({type, {a, b}});
        }
        bool ok = true;
        int ans = 0;
        vector<int> color(n, -1);
        //0 Imposter 1 Human
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(adj[i].size() == 0){
                    ans++;
                    continue;
                }
                int g = 0, r = 0;
                color[i] = 1;
                g++;
                queue<int> q;  
                q.push(i);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(auto u : adj[cur]){
                        int v = cur == u.second.first ? u.second.second : u.second.first;
                        if(color[v] == -1){
                            bool type = u.first;
                            if(type)
                                color[v] = color[cur];
                            else
                                color[v] = !color[cur];
                            q.push(v);
                            color[v] == 0 ? r++ : g++;
                        }else{
                            bool type = u.first;
                            int supposed = type ? color[cur] : !color[cur];
                            if(supposed != color[v]){
                                ok = false;
                                break;
                            }
                        }
                    }
                    if(!ok)
                    break;
                }
                if(!ok)
                    break;
                ans += max(r, g);
            }
        }
        if(!ok)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}