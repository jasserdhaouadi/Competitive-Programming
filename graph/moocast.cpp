// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=668
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
    // setIO("moocast");
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    ll l = 0, r = 1e11;
    while(r > l + 1){
        ll mid = l + (r - l) / 2;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    ll d = abs(x[i] - x[cur]) * abs(x[i] - x[cur]) + 
                           abs(y[i] - y[cur]) * abs(y[i] - y[cur]);
                    if(d <= mid){
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        bool ok = true;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ok = false;
                break;
            }
        }
        if(ok)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
    return 0;
}