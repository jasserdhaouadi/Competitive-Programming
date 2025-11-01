// Problem link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G
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
    ll c;
    string s;
    cin >> n >> c >> s;
    
    int ans = 0, l = 0;
    int cnt_a = 0, cnt_b = 0;
    ll rudeness = 0;
    for(int r=0; r<n; r++){
        if(s[r] == 'a'){
            cnt_a++;
        }else if(s[r] == 'b'){
            cnt_b++;
            rudeness += cnt_a;
        }
        while(rudeness > c){
            if(s[l] == 'a'){
                rudeness -= cnt_b;
                cnt_a--;
            }else if(s[l] == 'b'){
                cnt_b--;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}