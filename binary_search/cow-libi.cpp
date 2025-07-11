// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1303
#include <bits/stdc++.h>

#define ll long long
using namespace std;
 
void setIO(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const ll INF = 1e9;
struct event{
    ll x, y, t;
};
ll dis(ll x1, ll x2, ll y1, ll y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("haybales");
    int g, n;
    cin >> g >> n;
    vector<event> cow(n), graze(g);
    for(int i=0; i<g; i++){
        cin >> graze[i].x >> graze[i].y >> graze[i].t;
    }
    for(int i=0; i<n; i++){
        cin >> cow[i].x >> cow[i].y >> cow[i].t;
    }
    int ans = 0;
    sort(graze.begin(), graze.end(), [](const event& a, const event& b){return a.t < b.t;});
    for(int i=0; i<n; i++){
        auto right_it = lower_bound(graze.begin(), graze.end(), cow[i].t, [](const event& e, ll t){return e.t < t;});
        ll right = right_it - graze.begin();
        if(right == 0){
            ll d = dis(cow[i].x, graze[right].x, cow[i].y, graze[right].y);
            ll time = (cow[i].t - graze[right].t) * (cow[i].t - graze[right].t);
            if(d > time){
                ans++;
            }
        }else if(right == g){
            ll left = right - 1;
            ll d = dis(cow[i].x, graze[left].x, cow[i].y, graze[left].y);
            ll time = (cow[i].t - graze[left].t) * (cow[i].t - graze[left].t);
            if(d > time){
                ans++;
            }
        }else{
            ll left = right - 1;
            ll d1 = dis(cow[i].x, graze[right].x, cow[i].y, graze[right].y);
            ll time1 = (cow[i].t - graze[right].t) * (cow[i].t - graze[right].t);
            ll d2 = dis(cow[i].x, graze[left].x, cow[i].y, graze[left].y);
            ll time2 = (cow[i].t - graze[left].t) * (cow[i].t - graze[left].t);
            if(d1 > time1 || d2 > time2){
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}