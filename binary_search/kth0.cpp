// Problem link: https://codeforces.com/problemset/problem/1520/F1
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
    // setIO("convention");
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n;
    int done_0 = 0;
    while(r > l + 1){
        int m = l + (r - l) / 2;
        int sum;
        cout << "? " << l << " " << m << endl;
        cin >> sum;
        int n_0 = m - l + 1 - sum;
        if(n_0 + done_0 < k){
            l = m + 1;
            done_0 += n_0;
        }
        else
            r = m;
    }
    cout << "? " << 1 << " " << l << endl;
    int a, ans;
    cin >> a;
    ans = a == l - k ? l : r;
    cout << "! " << ans << endl;
    return 0;
}