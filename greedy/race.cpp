// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=989

#include <bits/stdc++.h>
#include <unordered_set>

typedef long long  ll; 
using namespace std;
 
void setIO(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const int INF = 1e9;
ll sum(int x){
    return (ll)x * (x + 1) / 2;
}
int next_speed(int k, int x, int d, int v){
    if(v < x){
        return ++v;
    }
    //distance needed to achive speed x
    ll remaining_distance = (ll) k - d;
    ll distance_needed = sum(v+1) - sum(x-1);
    if(distance_needed <= remaining_distance){
        return ++v;
    }
    distance_needed = sum(v) - sum(x-1);
    if(distance_needed <= remaining_distance){
        return v;
    }
    return --v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("race");
    int k, n;
    cin >> k >> n;
    while(n--){
        int x;
        cin >> x;
        int t = 0, d = 0, v = 0;
        while(d < k){
            v = next_speed(k, x, d, v);
            d += v;
            t++;
        }
        cout << t << '\n';
    }
    return 0;
}
