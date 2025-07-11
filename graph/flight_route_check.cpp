// Problem link: https://cses.fi/problemset/task/1682
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
    int  n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), rev_adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    {
        vector<bool> visited(n);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int j : adj[current]){
                if(!visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cout << "NO\n";
                cout << 1 << " " << i + 1 << '\n';
                return 0;
            }
        }
    }
    {
        vector<bool> visited(n);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int j : rev_adj[current]){
                if(!visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cout << "NO\n";
                cout << i + 1 << " " << 1 << '\n';
                return 0;
            }
        }
    }
    cout << "YES" << '\n';
    return 0;
}