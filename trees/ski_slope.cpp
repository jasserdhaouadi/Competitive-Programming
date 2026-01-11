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
    vector<int> p(n), d(n), e(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i] >> d[i] >> e[i];
        --p[i];
    }
    vector<ll> total_e(n);
    total_e[0] = 0;
    for (int i = 1; i < n; ++i) {
        total_e[i] = (ll)e[i] + total_e[p[i]];
    }
    int m;
    cin >> m;
    vector<int> s(m), c(m);
    int max_c = 0;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> c[i];
        max_c = max(max_c, c[i] + 1);
    }
    vector<vector<int>> top_d(n);
    top_d[0].push_back(-1);
    for (int i = 1; i < n; ++i) {
        top_d[i] = top_d[p[i]];
        auto it =
            lower_bound(top_d[i].begin(), top_d[i].end(), d[i], greater<int>());
        top_d[i].insert(it, d[i]);
        if (top_d[i].size() > max_c + 1) {
            top_d[i].pop_back();
        }
    }

    vector<vector<pair<int, ll>>> precompute(max_c + 1);
    for (int i = 0; i < max_c + 1; ++i) {
        auto& cur = precompute[i];
        cur.push_back({0, 0});
        for (int j = 1; j < n; ++j) {
            cur.push_back({top_d[j][i], total_e[j]});
        }
        sort(cur.begin(), cur.end());
        for (int j = 1; j < n; ++j) {
            cur[j].second = max(cur[j].second, cur[j - 1].second);
        }
    }
    for (int i = 0; i < m; ++i) {
        auto& arr = precompute[c[i]];
        auto it = upper_bound(
            arr.begin(), arr.end(), s[i],
            [](int value, const auto& elem) { return elem.first > value; });
        if (it == arr.begin()) {
            cout << "0\n";
        } else {
            cout << (--it)->second << '\n';
        }
    }
    return 0;
}
