// Problem link: https://cses.fi/problemset/task/1641/
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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        a[i] = {i + 1, k};
    }
    sort(a.begin(), a.end(), [](const auto& c, const auto& d){
        return c.second < d.second;
    });
    for(int i=0; i<n; i++){
        int sum = x - a[i].second;
        int l = i == 0 ? 1 : 0;
        int r = i == n - 1 ? n - 2 : n - 1;
        while(r > l){
            int add = a[r].second + a[l].second;
            if(add == sum){
                cout << a[i].first << " " << a[l].first << " " << a[r].first << '\n';
                return 0;
            }
            if(add > sum){
                if(--r == i){
                    --r;
                }
            }else{
                if(++l == i){
                    ++l;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}