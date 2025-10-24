#include<bits/stdc++.h>

using namespace std;

#define int long long
void solve() {
   int n, m;
	cin >> n >> m;
    int total=0;
	vector<string> grid(n);
	for (auto &s: grid) cin >> s;
    for(auto &s:grid){
        for(auto &c:s){
            total+=(c=='#');
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=min(n,m);i>0;i--){
        if(total%(i*i)==0){
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    if(grid[x][y]=='#'){
                        vis[x][y]=1;
                    }
                }
            }
            bool flag=true;
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    if(vis[x][y]==1){
                        for(int dx=x;dx<x+i;dx++){
                            for(int dy=y;dy<y+i;dy++){
                                if(dx>=n||dy>=m||!vis[dx][dy]){
                                    flag=false;
                                    break;
                                }
                                vis[dx][dy]=0;
                            }
                            if(!flag)break;
                        }
                       if(!flag)break;
                    }
                }
                if(!flag)break;
            }
            if(flag){cout<<i<<endl;return;}
        }
    }
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
}