// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=620
#include <bits/stdc++.h>
#include <unordered_set> 

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
    // setIO("pails");
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    vector<vector<bool>> vis(x+1, vector<bool> (y+1, false));
    vis[0][0] = true;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    int ans = m;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        ans = min(ans, abs(cur.second.first+cur.second.second-m));
        if(cur.first < k){
            //fill 1
            if(!vis[cur.second.first][y]){
                vis[cur.second.first][y] = true;
                q.push({cur.first+1, {cur.second.first, y}});
            }
            if(!vis[x][cur.second.second]){
                vis[x][cur.second.second] = true;
                q.push({cur.first+1, {x, cur.second.second}});
            }
            //empty 1
            if(!vis[cur.second.first][0]){
                vis[cur.second.first][0] = true;
                q.push({cur.first+1, {cur.second.first, 0}});
            }
            if(!vis[0][cur.second.second]){
                vis[0][cur.second.second] = true;
                q.push({cur.first+1, {0, cur.second.second}});
            }
            //pour
            int a = max(0, cur.second.first+cur.second.second-y);
            int b = min(y, cur.second.first+cur.second.second);
            if(!vis[a][b]){
                vis[a][b] = true;
                q.push({cur.first+1, {a, b}});
            }
            a = min(x, cur.second.first+cur.second.second);
            b = max(0, cur.second.first+cur.second.second-x);
            if(!vis[a][b]){
                vis[a][b] = true;
                q.push({cur.first+1, {a, b}});
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}