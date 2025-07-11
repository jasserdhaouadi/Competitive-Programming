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
    string s;
    cin >> s;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll ruble;
    cin >> ruble;
    vector<int> v(3, 0);
    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == 'B')
            v[0]++;
        else if(s[i] == 'C')
            v[1]++;
        else
            v[2]++;
    }
    ll l = 0, r = 1e12;
    while(r > l + 1){
        ll m = (r - l) / 2 + l;
        ll b_need = max(v[0] * m - nb, (ll)0);
        ll c_need = max(v[1] * m - nc, (ll)0);
        ll s_need = max(v[2] * m - ns,(ll)0);
        ll price  = b_need * pb + c_need * pc + s_need * ps;
        if(price > ruble)
            r = m;
        else
            l = m;
    }
    cout << l << '\n';
    return 0;
}