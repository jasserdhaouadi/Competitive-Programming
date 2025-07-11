// Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=740
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

struct rect{
    int x0, x1, y0, y1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("where");
    int n;
    cin >> n;
    vector<string> grid(n);
    for(string& s : grid)
        cin >> s;
    vector<rect> plc;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            for(int k=0; k<=i; k++){
                for(int z=0; z<=j; z++){
                    bool ok = true;
                    for(const auto& r : plc){
                        if(i <= r.x1 && k >= r.x0 && j <= r.y1 && z >= r.y0){
                            ok = false;
                            break;
                        }
                    }
                    unordered_set<char> s;
                    char first = '.', second = '.';
                    int n_con1 = 0, n_con2 = 0;
                    vector<vector<bool>> vis(n, vector<bool> (n, false));
                    for(int x=k; x<=i; x++){
                        for(int y=z; y<=j; y++){
                            if(!vis[x][y]){
                                vis[x][y] = true;
                                queue<pair<int, int>> q;
                                q.push({x, y});
                                char c = grid[x][y];
                                if(s.find(c) == s.end())
                                    s.insert(c);
                                if(s.size() > 2){
                                    ok = false;
                                    break;
                                }
                                if(first == '.')
                                    first = c;
                                if(first != '.' && first != c)
                                    second = c;
                                first == c ? n_con1++ : n_con2++;
                                while(!q.empty()){
                                    auto cur = q.front();
                                    q.pop();
                                    for(const auto& d : directions){
                                        int a = cur.first + d.first;
                                        int b = cur.second + d.second;
                                        if(a > i || a < k || b > j || b < z)
                                            continue;
                                        if(!vis[a][b] && grid[a][b] == c){
                                            vis[a][b] = true;
                                            q.push({a, b});
                                        }
                                    }
                                }
                            }
                            if(!ok)
                                break;
                        }
                        if(!ok)
                        break;
                    }                   
                    if(ok && abs(n_con1 - n_con2) >= 1 && (n_con1 == 1 || n_con2 == 1) && (n_con1 != 0 && n_con2 != 0)){
                        plc.push_back({k, i, z, j});
                    }
                }
            }
        }
    }
    cout << (int) plc.size() << '\n';
    return 0;
}