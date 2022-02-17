class Solution {
public:
    int dp[310][10010];
    int n;
    
    int solve(int i, int amt, vector<int>& coins)
    {
        if(amt == 0) return 1;
        if(i < 0) return 0;
        if(dp[i][amt] != -1) return dp[i][amt];
        
        int ways = 0;
        for(int curr_amt = 0; curr_amt <= amt; curr_amt += coins[i])
        {
            ways += solve(i-1, amt - curr_amt, coins);
        }
        
        return dp[i][amt] = ways;
    }
    
    int change(int target, vector<int>& coins) {
        n = coins.size();
        memset(dp, -1, sizeof(dp));
        
        int x = solve(n-1, target, coins);
        // int ans = 0;
        return x;
    }
};