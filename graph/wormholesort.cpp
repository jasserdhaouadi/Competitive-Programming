// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=992
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

struct worm{
    int a, b, w;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("wormsort");
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<worm> v(m);
    bool ok = true;
    for(int i=0; i<n; i++){
        cin >> p[i];
        --p[i];
        if(p[i] != i)
            ok = false;
    }
    for(int i=0; i<m; i++){
        cin >> v[i].a >> v[i].b >> v[i].w;
        --v[i].a, --v[i].b;
    }
    if(ok)
        cout << -1 << '\n';
    else{
        sort(v.begin(), v.end(), [](worm x, worm y){
            return x.w < y.w;
        });
        int l = 0, r = m - 1;
        while(r > l + 1){
            int mid = l + (r - l) / 2;
            vector<vector<int>> adj(n);
            for(int i=mid; i<m; i++){
               int f = v[i].a;
               int s = v[i].b;
               adj[f].push_back(s);
               adj[s].push_back(f);
            }
            vector<bool> vis(n, false);
            queue<int> q;
            bool boo = true;
            for(int i=0; i<n; i++){
                if(adj[i].size() > 0 && !vis[i]){
                    vis[i] = true;
                    q.push(i);
                    unordered_set<int> s;
                    s.emplace(i);
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        for(int j : adj[cur]){
                            if(!vis[j]){
                                vis[j] = true;
                                q.push(j);
                                s.emplace(j);
                            }
                        }
                    }
                    unordered_set<int> cow;
                    for(auto it : s)
                        cow.emplace(p[it]);
                    if(cow != s){
                        boo = false;
                        break;
                    }
                }
            }
            if(boo){
                for(int i=0; i<n; i++){
                    if(!vis[i] && p[i] != i){
                        boo = false;
                        break;
                    }
                }
            }
            if(boo)
                l = mid;
            else
                r = mid;
        }
        cout << v[l].w << '\n';
    }
    return 0;
}