// Problem link: https://atcoder.jp/contests/abc125/tasks/abc125_c
#include <bits/stdc++.h>

#include <unordered_set>

typedef long long ll;
using namespace std;

void dbg(int* x) { cerr << " = " << *x << " "; }

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> v[i];
    }
    vector<int> left_prefix(n + 1), right_prefix(n + 2);
    left_prefix[0] = 0;
    right_prefix[n + 1] = 0;
    for (int i = 1; i < n + 1; ++i) {
        left_prefix[i] = gcd(left_prefix[i - 1], v[i]);
    }
    for (int i = n; i >= 1; --i) {
        right_prefix[i] = gcd(right_prefix[i + 1], v[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, gcd(left_prefix[i - 1], right_prefix[i + 1]));
    }
    cout << ans << '\n';
    return 0;
}
