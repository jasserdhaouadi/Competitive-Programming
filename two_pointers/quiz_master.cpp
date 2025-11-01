// Problem link: https://codeforces.com/contest/1777/problem/C
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
    vector<vector<int>> fact(1e5+1);
    for(int i=1; i<=1e5; i++){
        for(int j=i; j<=1e5; j+=i){
            fact[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> freq(m+1, 0);
        for(int& i : a)
            cin >> i;
        sort(a.begin(), a.end());
        int ans = 1e9 + 5;
        int cnt = 0;
        int l = 0;
        for(int r=0; r<n; r++){
            for(int& i : fact[a[r]]){
                if(i > m)
                    continue;
                if(++freq[i] == 1)
                    cnt++;
            }
            while(cnt == m){
                ans = min(ans, a[r] - a[l]);
                for(int& i : fact[a[l]]){
                    if(i > m)
                        continue;
                    if(--freq[i] == 0)
                        cnt--;
                }
                l++;
            }
        }
        if(ans == 1e9 + 5)
            cout << "-1\n";
        else 
            cout << ans << '\n';
    }
    return 0;
}
