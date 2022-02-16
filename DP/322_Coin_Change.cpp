class Solution {
public:
    int dp[10010];
    int n;
    
    int solve(int amt, vector<int>& coins)
    {
        if(amt == 0) return 0;
        if(dp[amt] != -1) return dp[amt];
        
        int ans = INT_MAX;
        for(int coin: coins){
            if(amt - coin >= 0)
               ans = min(ans + 0ll, solve(amt - coin, coins) + 1ll);
        }
        
        return dp[amt] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        if(amount == 0)
            return 0;
        
        memset(dp, -1, sizeof(dp));
        int ans = solve(amount, coins);
        return ans == INT_MAX? -1: ans;
    }
};