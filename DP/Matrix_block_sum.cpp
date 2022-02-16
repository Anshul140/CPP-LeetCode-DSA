/*
Prefix Sum in  2D Arrays

Tips:
- Make 2d prefix array with 1 based indexing

<-- Equation: Assuming 1 based indexing of both the matrix -->
- pre[i][j] = mat[i][j] + pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1]

<-- calculating sum of a rectangular block from coordinates (a,b) to (c,d) -->
- val = pre[c][d] - pre[a-1][d] - pre[c][b-1] + pre[a-1][b-1]

*/

class Solution {
public:
    int pre[105][105];
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        memset(pre, 0, sizeof(pre));
        
        int m = mat.size(), n = mat[0].size();
        
        pre[1][1] = mat[0][0];
        for(int i = 1; i<n; i++) pre[1][i+1] = mat[0][i] + pre[1][i];     
        for(int i = 1; i<m; i++) pre[i+1][1] = mat[i][0] + pre[i][1];
        
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                pre[i+1][j+1] = mat[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j];
            }
        }
        
        vector<vector<int>> ans( m , vector<int> (n, 0));
        for(int i = 1; i<=m; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                int a = max(1, i-k);
                int b = max(1, j-k);
                
                int c = min(m, i+k);
                int d = min(n, j+k);
                
                ans[i-1][j-1] = pre[c][d] - pre[a-1][d] - pre[c][b-1] + pre[a-1][b-1];
            }
        }
        return ans;
    }
};