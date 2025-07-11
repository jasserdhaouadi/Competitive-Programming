// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=570
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
    // setIO("lightson");
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n*n);
    for(int i=0; i<m; i++){
        int x, y, w, z;
        cin >> x >> y >> w >> z;
        --x, --y, --w, --z;
        v[x*n+y].push_back({w, z});
    }
    int ans = 1;
    vector<vector<bool>> vis(n, vector<bool> (n, false));
    vector<vector<bool>> lit(n, vector<bool> (n, false));
    vis[0][0] = true;
    lit[0][0] = true;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> reach(n, vector<bool> (n, false));
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for(const auto& u : v[x*n+y]){
            if(!lit[u.first][u.second]){
                lit[u.first][u.second] = true;
                ans++;
                if(!vis[u.first][u.second] && reach[u.first][u.second]){
                    vis[u.first][u.second] = true;
                    q.push({u.first, u.second});
                }
            }
        }
        for(const auto& d : dir){
            int a = x + d.first;
            int b = y + d.second;
            if(a < 0 || b < 0 || a == n || b == n)
                continue;
            if(!vis[a][b] && lit[a][b]){
                vis[a][b] = true;
                q.push({a, b});
            }else if(!vis[a][b])
                reach[a][b] = true;
        }
    }
    std::cout << ans << '\n';
    return 0;
}