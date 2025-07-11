// Problem link: https://codeforces.com/contest/862/problem/B
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
int g1 = 0, g2 = 0;
vector<vector<int>> adj;
void dfs(int start, int mother, int idx){
    if(idx % 2 == 0)
        g1++;
    else
        g2++;
    for(int u : adj[start]){
        if(u != mother)
            dfs(u, start, idx + 1);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("revegetate");
    int n;
    cin >> n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0, 0);
    cout << (ll)g1 * g2 - (n - 1) << '\n';
    return 0;
}