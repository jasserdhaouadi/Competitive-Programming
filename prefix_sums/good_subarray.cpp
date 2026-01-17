// Problem link: https://codeforces.com/contest/1398/problem/C
#include <bits/stdc++.h>

#include <unordered_set>

typedef long long ll;
using namespace std;

void dbg(int* x) { cerr << " = " << *x << " "; }

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll prefix_sum = 0;
        map<ll, ll> m;
        ++m[0];
        for (int i = 1; i <= n; ++i) {
            char c;
            cin >> c;
            prefix_sum += c - '0';
            ++m[prefix_sum - i];
        }
        ll ans = 0;
        for (auto& [k, v] : m) {
            ans += v * (v - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
