// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=643
#include <bits/stdc++.h>
#include <unordered_set>

typedef long long  ll;
using namespace std;
 
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const int INF = 1e9;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    vector<int> can_take(n);
    int r = 0;
    for(int l=0; l<n; l++){
        while(r < n && v[r] - v[l] <= k)
            r++;
        can_take[l] = r - l;
    }
    vector<int> max_val(n+1);
    max_val[n] = 0;
    for(int i=n-1; i>=0; i--){
        max_val[i] = max(max_val[i+1], can_take[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, can_take[i] + max_val[i+can_take[i]]);
    }
    cout << ans << '\n';
    return 0;
}
