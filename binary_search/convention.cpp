// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=858
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
void dbg(int* x) { cerr << " = " << *x << " "; }

const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("convention");
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    int l = 0, r = 1e9;
    while (r > l + 1) {
        int mid = l + (r - l) / 2;
        int j = 0;
        int cur = 0;
        for (int i = 0; i < n && j <= m; i++) {
            if (cur == 0) {
                j++;
                cur++;
            } else if (cur < c && v[i] - v[i - cur] <= mid) {
                cur++;
            } else {
                j++;
                cur = 1;
            }
        }
        if (j <= m) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    return 0;
}