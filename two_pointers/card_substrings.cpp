// Problem link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F
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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> freq(26);
    for(char c : s2)
        freq[c - 'a']++;
    int l = 0;
    ll ans = 0;
    unordered_map<char, int> ma;
    for(int r=0; r<n; r++){
        ma[s1[r]]++;
        while(ma[s1[r]] > freq[s1[r] - 'a']){
            ma[s1[l]]--;
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';
    return 0;
}