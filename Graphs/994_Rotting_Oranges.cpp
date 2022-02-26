#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vl vector<ll>
#define Map map<ll, ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define PYes cout<<"YES\n"
#define PNo cout<<"NO\n"
#define fl(i, a, b) for(int i=a;i<b;i++)
#define endl "\n"
#define cov(x) (x).begin(),(x).end()

bool vis[15][15];
int m, n;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isValid(int x, int y, vector<vector<int>>& grid)
{
    if(x < 0 or x >= m or y < 0 or y >= n) return false;
    if(vis[x][y] or grid[x][y] == 0 or grid[x][y] == 2) return false;

    return true;
}
int orangesRotting(vector<vector<int>>& grid) {

    //stores time frame, and coordinates of rotten oranges
    queue<pair<int, pair<int, int>>> qp;

    m = grid.size(), n = grid[0].size();
   
    memset(vis, false, sizeof(vis));
    
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(grid[i][j] == 2)
            {
                qp.push({0, {i,j}});
                vis[i][j] = true;
            }    
        }
    }
    
    int ans = 0;
    while(!qp.empty())
    {
        auto it = qp.front();
        qp.pop();
        int cx = it.second.first;
        int cy = it.second.second;
        int c_time = it.first;
        ans = c_time;
        for(int i = 0; i<4; i++)
        {
            if(isValid(cx + dir[i].first, cy+dir[i].second, grid))
            {
                int nwx = cx + dir[i].first;
                int nwy = cy + dir[i].second;
                int nwt = c_time+1;
                vis[nwx][nwy] = true;
                qp.push({nwt, {nwx, nwy}});
            }
        }
    }
    
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(grid[i][j] == 1 and !vis[i][j])
                return -1; 
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int>> grid3 = {{0,2}};

    cout<<"ans1: "<<orangesRotting(grid)<<endl;
    cout<<"ans2: "<<orangesRotting(grid2)<<endl;
    cout<<"ans3: "<<orangesRotting(grid3)<<endl;
    return 0;
}