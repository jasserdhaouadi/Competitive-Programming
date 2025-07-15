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
template <class T>
T tmax(T a, T b){
    return a > b ? a : b;
}
const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("haybales");
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(ll& i : v){
        cin >> i;
    }
    cerr << '\n';
    sort(v.begin(), v.end());
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        auto low = lower_bound(v.begin(), v.end(), a);
        auto up = upper_bound(v.begin(), v.end(), b);
        cout << (up - v.begin()) - (low - v.begin()) << '\n';
    }
    return 0;
}