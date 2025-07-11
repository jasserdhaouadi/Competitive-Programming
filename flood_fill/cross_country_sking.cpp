// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=380
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
    // setIO("ccski");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m));
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin >> a;
            if(a == 1)
                v.push_back({i, j});
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int l = -1, r = 1e9;
    int x = v[0].first, y = v[0].second;
    while(r > l + 1){
        int mid = l + (r - l) / 2;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vis[x][y] = true;
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto d : dir){
                int a = cur.first + d.first;
                int b = cur.second + d.second;
                if(a < 0 || b < 0 || a == n || b == m || vis[a][b])
                    continue;
                if(abs(grid[cur.first][cur.second] - grid[a][b]) <= mid){
                    vis[a][b] = true;
                    q.push({a, b});
                }
            }
        }
        bool ok = true;
        for(auto k : v){
            if(!vis[k.first][k.second]){
                ok = false;
                break;
            }
        }
        if(ok)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
    return 0;
}