// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1038
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
 
const ll INF = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("socdist");
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(m, vector<ll> (2));
    for(int i=0; i<m; i++)
        cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end());
    ll l = 0, r = 1e18;
    while(r > l + 1){
        ll mid = l + (r - l) / 2;
        int j = 0;
        ll pos_last;
        for(int i=0; i<n && j<m; i++){
            if(i == 0)
                pos_last = v[j][0];
            else{
                while(j < m && pos_last + mid > v[j][1])
                    j++;
                if(j < m)
                    pos_last = max(v[j][0], mid + pos_last);
            }
        }
        if(j == m)
            r = mid;
        else
            l = mid;
    }
    cout << l << '\n';
    return 0;
}