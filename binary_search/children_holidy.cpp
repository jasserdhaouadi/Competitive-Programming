// Problem link:
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
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
    int m, n;
    cin >> m >> n;
    vector<int> t(n), z(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }
    int l = 0, r = 200 * m;
    while (r > l + 1) {
        int mid = l + (r - l) / 2;
        int nb_balloons = 0;
        for (int i = 0; i < n; i++) {
            int cycle = t[i] * z[i] + y[i];
            int nb_cycles = mid / cycle;
            nb_balloons += nb_cycles * z[i] + min(z[i], (mid % cycle) / t[i]);
        }
        if (nb_balloons >= m)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
    vector<int> res(n);
    int remaining = m;
    for (int i = 0; i < n && remaining > 0; i++) {
        int cycle = t[i] * z[i] + y[i];
        int nb_cycles = r / cycle;
        int nb_balloons = nb_cycles * z[i] + min(z[i], (r % cycle) / t[i]);
        res[i] = min(remaining, nb_balloons);
        remaining -= nb_balloons;
    }
    for (int i : res) cout << i << " ";
    cout << '\n';
    return 0;
}