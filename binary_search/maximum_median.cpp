// Problem link: https://codeforces.com/contest/1201/problem/C
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
    // setIO("haybales");
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    ll l = 0, r = 1e12;
    int median = n / 2;
    // dbg(&median);
    // cerr << v[median] << '\n';
    while(r > l + 1){
        ll  m = l + (r - l) / 2;
        ll sum = (ll)k - m;
        for(int i=median+1; i<n && sum >= 0; i++){
            sum -= max((ll)v[median] + m - v[i], (ll)0);
        }
        if(sum < 0)
            r = m;
        else
            l = m;
    }
    cout << v[median] + l << '\n';
    return 0;
}