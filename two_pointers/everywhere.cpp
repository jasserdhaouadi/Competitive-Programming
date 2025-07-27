// Problem link: https://codeforces.com/problemset/problem/701/C
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
    int n;
    string s;
    cin >> n >> s;
    unordered_set<char> mys;
    for(const char& c : s){
        if(mys.find(c) == mys.end()){
            mys.insert(c);
        }
    }
    int ans = INF;
    map<char, int> m;
    int l = 0;
    int r = 0;
    for(; r<n; r++){
        m[s[r]]++;
        while(m[s[l]] > 1){
            m[s[l]]--;
            l++;
        }
        if(m.size() == mys.size()){
            ans = min(ans, r - l + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
