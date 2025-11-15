//Problem link: https://codeforces.com/contest/839/problem/C
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
struct state{
    int u;
    int parent;
    int depth;
    long double prob;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("mootube");
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=1 ;i<n; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long double ans = 0;
    queue<state> q;
    //node, parent, depth, prob
    q.push({0, 0, 0, 1.0});
    while(!q.empty()){
        state s = q.front();
        q.pop();
        for(int& i : adj[s.u]){
            if(i != s.parent){
                if(s.u == 0){
                    q.push({i, s.u, s.depth + 1, s.prob / adj[s.u].size()});
                }else{
                    q.push({i, s.u, s.depth + 1, s.prob / (adj[s.u].size() - 1)});
                }
            }
        }
        if(adj[s.u].size() == 1 && s.u != 0){
            ans += s.depth * s.prob;
        }
    }   
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
