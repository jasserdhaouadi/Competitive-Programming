// Problem Link: https://cses.fi/problemset/task/1674/
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

void dfs(int node, const vector<vector<int>>& children, vector<int>& ret){
    if(children[node].size() == 0){
        return;
    }
    for(int child : children[node]){
        dfs(child, children, ret);
        ret[node] += 1 + ret[child];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("race");
    int n;
    cin >> n;
    vector<vector<int>> children(n);
    for(int i=1; i<n; i++){
        int x;
        cin >> x;
        children[x-1].push_back(i);
    }
    vector<int> ret(n, 0);
    dfs(0, children, ret);
    for(int i=0; i<n; i++){
        cout << ret[i];
        if(i != n - 1)
            cout << " ";
    }
    cout << '\n';
    return 0;
}
