// Problem link: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("haybales");
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i : v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        int l = -1, r = n;
        int left, right;
        //left has the first i such that v[i] >= x
        while(r > l + 1){
            int m = l + (r - l) / 2;
            if(v[m] < x)
                l = m;
            else
                r = m;
        }
        left = r;
        //right has the last i such that v[i] <= y
        l = -1, r = n;
        while(r > l + 1){
            int m = l + (r - l) / 2;
            if(v[m] <= y)
                l = m;
            else
                r = m;
        }
        right = l;
        cout << right - left + 1 << '\n';
    }
    return 0;
}