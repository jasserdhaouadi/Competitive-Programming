// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=895
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
    int n;
    cin >> n;
    vector<string> grid(n);
    for(string& s : grid)
        cin >> s;
    pair<int, int> ans = {0, 0};
    vector<vector<bool>> vis(n, vector<bool> (n));
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j] && grid[i][j] == '#'){
                vis[i][j] = true;
                int area = 0, per = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    area++;
                    for(const auto& d : dir){
                        int x = d.first + cur.first;
                        int y = d.second + cur.second;
                        //If the neighbour cell is outside the grid or '.' it counts in the permiter
                        if(x < 0 || y < 0 || x == n || y == n || grid[x][y] == '.')
                            per++;
                        else if(!vis[x][y]){
                            vis[x][y] = true;
                            q.push({x, y});
                        }
                    }
                }
                if(area > ans.first){
                    ans.first = area;
                    ans.second = per;
                }else if(area == ans.first)
                    ans.second = min(ans.second, per);
            }
        }
    }
    cout << ans.first << " " << ans.second << '\n';
    return 0;
}