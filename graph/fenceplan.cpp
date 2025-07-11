// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=944
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void setIO(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const ll INF = 1e15;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("fenceplan");
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = INF;
    vector<bool> visited(n);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            queue<int> q;
            q.push(i);
            ll xmax = 0, ymax = 0;
            ll xmin = INF, ymin = INF;
            while(!q.empty()){
                int current = q.front();
                q.pop();
                xmax = xmax > x[current] ? xmax : x[current];
                ymax = ymax > y[current] ? ymax : y[current];
                xmin = xmin < x[current] ? xmin : x[current];
                ymin = ymin < y[current] ? ymin : y[current];
                
                for(int j : adj[current]){
                    if(!visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            ans = min(ans, (ll)2*((xmax-xmin)+(ymax-ymin)));
        }
    }
    cout << ans << '\n';
    return 0;
}
