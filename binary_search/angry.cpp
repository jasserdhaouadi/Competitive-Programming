// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=594
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
    // setIO("angry");
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int l = 0, r = 1e9;
    while(r > l + 1){
        int m = l + (r - l) / 2;
        int j = 0;
        int f;
        for(int i=0; i<n && j<= k; i++){
            if(i == 0){
                f = i;
                j++;
            }else if(v[i] - v[f] <= 2*m)
                continue;
            else{
                f = i;
                j++;
            }
        }
        if(j <= k)
            r = m;
        else 
            l = m;
    }
    cout << r << '\n';
    return 0;
}