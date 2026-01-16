// Problem link: https://codeforces.com/contest/702/problem/C
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
    // setIO("haybales");
    int n, m;
    cin >> n >> m;
    vector<int> c(n), t(m);
    for (int& i : c) {
        cin >> i;
    }
    for (int& i : t) {
        cin >> i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int up = (int)(lower_bound(t.begin(), t.end(), c[i]) - t.begin());
        int low = up - 1;
        // low == t.begin()
        if (up == 0) {
            ans = max(ans, t[up] - c[i]);
            // low == t.end()
        } else if (up == m) {
            ans = max(ans, c[i] - t[low]);
        } else if (t[up] == c[i]) {
            continue;
        } else {
            int r = min(c[i] - t[low], t[up] - c[i]);
            ans = max(ans, r);
        }
    }
    cout << ans << '\n';
    return 0;
}