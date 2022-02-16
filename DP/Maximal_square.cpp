class Solution {
public:
    int pre[305][305];
    int maximalSquare(vector<vector<char>>& mat) {
        memset(pre, 0, sizeof(pre));
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        
        for(int i = 0; i<n; i++)
        {
             pre[0][i] = mat[0][i] - '0';
             ans = max(ans, pre[0][i]);
        }
        for(int i = 0; i<m; i++) 
        {
            pre[i][0] = mat[i][0] - '0';
            ans = max(ans, pre[i][0]);
        }
        
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(pre[i-1][j] > 0 and pre[i-1][j-1] > 0 and pre[i][j-1] > 0)
                {
                    int val = min({pre[i-1][j], pre[i][j-1], pre[i-1][j-1]});
                    if(mat[i][j] - '0')
                    {
                        pre[i][j] = 1 + val;
                        ans = max(ans, pre[i][j]);
                    }    
                    else
                        pre[i][j] = 0;
                }
                else{
                     pre[i][j] = mat[i][j]-'0';
                     ans = max(ans, pre[i][j]);
                }    
            }
        }
        return ans*ans;
    }
};