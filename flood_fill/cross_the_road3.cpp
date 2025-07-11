// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=716
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
    // setIO("countcross");
    int n, k, r;
    cin >> n >> k >> r;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<bool>> right(n, vector<bool>(n, false));
    vector<vector<bool>> down(n, vector<bool>(n, false));
    for(int i=0; i<r; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        if(x1 == x2)
            right[x1][min(y1, y2)] = true;
        else
            down[min(x1, x2)][y1] = true;
    }
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        --x, --y;
        grid[x][y] = 1;
    }
    int ans = 0;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]){
                vector<vector<bool>> vis(n, vector<bool> (n, false));
                vis[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(const auto& d : dir){
                        int x = cur.first + d.first;
                        int y = cur.second + d.second;
                        if(x < 0 || y < 0 || x == n || y == n)
                            continue;
                        if(!vis[x][y]){
                            if(x == cur.first){
                                if(!right[x][min(cur.second, y)]){
                                    vis[x][y] = true;
                                    q.push({x, y});
                                }
                            }else if(!down[min(cur.first, x)][y]){
                                vis[x][y] = true;
                                q.push({x, y});
                            }
                        }
                    }
                }
                for(int x=0; x<n; x++){
                    for(int y=0; y<n; y++){
                        if(!vis[x][y] && grid[x][y])
                            ans++;
                    }
                }       
            }
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}