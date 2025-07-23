// Problem link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G?locale=en
#include <bits/stdc++.h>
#include <unordered_set>

typedef long long  ll;
using namespace std;
 
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const int INF = 1e9;

struct qu{
    stack<ll> in, out, gcd_in, gcd_out;
    void push(ll x){
        in.emplace(x);
        if(gcd_in.empty())
            gcd_in.emplace(x);
        else
            gcd_in.emplace(gcd(gcd_in.top(), x));
    }
    ll pop(){
        if(out.empty()){
            while(!in.empty()){
                out.emplace(in.top());
                if(gcd_out.empty())
                    gcd_out.emplace(in.top());
                else
                    gcd_out.emplace(gcd(gcd_out.top(), in.top()));
                in.pop();
                gcd_in.pop();
            }
        }
        ll ret = out.top();
        out.pop();
        gcd_out.pop();
        return ret;
    }
    bool empty(){
        return in.empty() && out.empty();
    }
    ll get_gcd(){
        if(empty())
            return INF;
        if(gcd_in.empty())
            return gcd_out.top();
        if(gcd_out.empty())
            return gcd_in.top();
        return gcd(gcd_in.top(), gcd_out.top());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll& i : a){
        cin >> i;
    }
    int l = 0;
    ll ans = LLONG_MAX;
    qu q;
    for(int r=0; r<n; r++){
        q.push(a[r]);
        while(q.get_gcd() == 1 && l <= r){
            ans = min(ans, (ll)r - l + 1);
            q.pop();
            l++;
        }
    }
    if(ans == LLONG_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
    
}
