// Problem link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/H
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
    int n, m, s, a, b;
    cin >> n >> m  >> s >> a >> b;
    vector<int> set1(n);
    for(int& i : set1)
        cin >> i;
    vector<int> set2(m);
    for(int& i : set2)
        cin >> i;
    sort(set1.begin(), set1.end(), [](const int& a, const int& b){
        return a > b;
    });
    sort(set2.begin(), set2.end(), [](const int& a, const int& b){
        return a > b;
    });
    int cnt_s1 = min(n, s / a);
    int cnt_s2 = 0;
    ll total_weight = cnt_s1 * a;
    ll total_cost = 0;
    cnt_s1--;
    if((s - total_weight) / b >= 0){
        cnt_s2 = min((s - total_weight) / b, (ll) m);
        total_weight += cnt_s2 * b;
    }
    for(int i=0; i<=cnt_s1; i++){
        total_cost += set1[i];
    }
    for(int i=0; i<cnt_s2; i++){
        total_cost += set2[i];
    }
    ll ans = total_cost;
    for(; cnt_s1 >= 0; cnt_s1--){
        total_weight -= a;
        total_cost -= set1[cnt_s1];
        while((s - total_weight) >= b && cnt_s2 < m){
            total_weight += b;
            total_cost += set2[cnt_s2];
            cnt_s2++;
        }
        cerr << cnt_s1 << " " << cnt_s2 - 1 << " " << total_weight << " " << total_cost << '\n';
        ans = max(total_cost, ans);
    }
    cout << ans << '\n';
    return 0;
}