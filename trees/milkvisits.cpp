// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=968
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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> comp(n, -1);
    comp[0] = 0;
    int comp_num = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int& i : adj[cur]){
            if(comp[i] != -1)
                continue;
            q.push(i);
            if(s[i] == s[cur]){
                comp[i] = comp[cur];
            }else{
                comp[i] = ++comp_num;
            }
        }
    }
    while(m--){
        int a, b;
        char c;
        cin >> a >> b >> c;
        --a, --b;
        if(comp[a] == comp[b]){
            if(s[a] == c)
                cout << "1";
            else
                cout << "0";
        }else
            cout << "1";
    }
    cout << '\n';
    return 0;
}
