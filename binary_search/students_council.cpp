// Problem link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
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
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    ll total = 0;
    for(int& i : v){
        cin >> i;
        total += (ll)i;
    }
    ll l = -1, r = total + 1;
    while(r > l + 1){
        ll m = l + (r - l) / 2;
        ll sum = 0;
        for(int i : v)
            sum += min(m, (ll)i);
        if(sum >= k * m)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
    return 0;
}