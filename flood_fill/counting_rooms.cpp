// Problem link: https://cses.fi/problemset/task/1192
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
    // setIO("revegetate");
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++)
        cin >> grid[i];
    vector<vector<bool>> vis(n, vector<bool> (m));
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j]){
                vis[i][j] = true;
                if(grid[i][j] == '#')
                    continue;
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(const auto& d : dir){
                        int x = d.first + cur.first;
                        int y = d.second + cur.second;
                        if(x < 0 || y < 0 || x == n || y == m)
                            continue;
                        if(grid[x][y] == '.' && !vis[x][y]){
                            vis[x][y] = true;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}