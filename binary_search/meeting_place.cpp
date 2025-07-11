// Problem link: https://codeforces.com/contest/782/problem/B
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
    int n;
    cin >> n;
    vector<vector<int>> x(n, vector<int> (2));
    for(int i=0; i<n; i++)
        cin >> x[i][0];
    for(int i=0; i<n; i++)
        cin >> x[i][1];
    sort(x.begin(), x.end());
    double l = 0.0, r = 1e9;
    for(int i=0; i<100; i++){
        double mid = l + (r - l) / 2;
        double mn = x[0][0];
        double mx = x[n-1][0];
        bool ok = true;
        for(int j=0; j<n; j++){
            double x0 = x[j][0] - mid * x[j][1];
            double x1 = x[j][0] + mid * x[j][1];
            if(max(x0, mn) > min(x1, mx)){
                ok = false;
                break;
            }else{
                mn = max(mn, x0);
                mx = min(mx, x1);
            }
        }
        if(ok)
            r = mid;
        else
            l = mid;
    }
    cout << setprecision(20) << r << '\n';
    return 0;
}