// Problem link: https://codeforces.com/contest/1365/problem/D
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
    // setIO("perimeter");
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for(string& s : grid)
            cin >> s;
        bool ok = true;
        vector<vector<bool>> vis(n, vector<bool> (m));
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 'B'){
                    vis[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(const auto& d : dir){
                            int x = cur.first + d.first;
                            int y = cur.second + d.second;
                            if(x < 0 || y < 0 || x == n || y == m)
                                continue;
                            if(grid[x][y] == 'B' && !vis[x][y]){
                                vis[x][y] = true;
                                q.push({x, y});
                            }else if(grid[x][y] == 'G'){
                                ok = false;
                                break;
                            }else{
                                grid[x][y] = '#';
                            }
                        }
                    }
                    if(!ok)
                        break;
                }
            }
            if(!ok)
                break;
        }
        if(!ok){
            cout << "NO\n";
            continue;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 'G'){
                    vis[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    bool okay = false;
                    vector<vector<bool>> local_vis(n, vector<bool>(m, false));
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(const auto& d : dir){
                            int x = cur.first + d.first;
                            int y = cur.second + d.second;
                            if(x < 0 || y < 0 || x == n || y == m)
                                continue;
                            if(grid[x][y] == 'G' && !vis[x][y]){
                                vis[x][y] = true;
                                q.push({x, y});
                            }else if(grid[x][y] == '.' && !local_vis[x][y]){
                                local_vis[x][y] = true;
                                q.push({x, y});
                            }
                            if(x == n - 1 && y == m - 1 && grid[x][y] == '.')
                                okay = true;
                        }
                    }
                    if(!okay){
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok)
                break;
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}