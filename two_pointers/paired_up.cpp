// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=738
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
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end(), [](const auto& c, const auto& d){
        return c.second < d.second;
    });
    int l = 0;
    int r = n - 1;
    int indx_l = 1, indx_r = 1;
    int ans = 0;
    while(r > l || (r == l && indx_r > indx_l)){
        int sum = a[r].second + a[l].second;
        ans = max(ans, sum);
        if(++indx_r > a[r].first){
            --r;
            indx_r = 1;
        }
        if(++indx_l > a[l].first){
            ++l;
            indx_l = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}