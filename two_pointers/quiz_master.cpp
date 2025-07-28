// Problem link: https://codeforces.com/contest/1777/problem/C
#include <bits/stdc++.h>
#include <unordered_set>

typedef long long  ll;
using namespace std;
 
void dbg(int* x){
    cerr << " = " << *x << " ";
}

const int INF = 1e9;

void compute(bool dir, int x, int m, vector<int>& freq, int& cnt){
    for(int i=1; i*i<=x && i<=m; i++){
        if(x % i == 0){
            if(dir){
                freq[i]++;
                freq[i] == 1 ? cnt++ : cnt;
                if(x / i <= m){
                    freq[x / i]++;
                    freq[x / i] == 1 ? cnt++ : cnt;
                }
            }else{
                freq[i]--;
                freq[i] == 0 ? cnt-- : cnt;
                if(x / i <= m){
                    freq[x / i]--;
                    freq[x / i] == 0 ? cnt-- : cnt;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int& i : a)
            cin >> i;
        sort(a.begin(), a.end());

        int ans = INF;
        int l = 0;
        vector<int> freq(m + 1, 0);
        int cnt = 0;
        for(int r=0; r<n; r++){
            compute(true, a[r], m, freq, cnt);
            while(cnt == m){
                ans = min(ans, a[r] - a[l]);
                compute(false, a[l], m, freq, cnt);
                l++;
            }
        }
        ans == INF ? cout << -1 : cout << ans;
        cout << '\n';
    }
    return 0;
}
