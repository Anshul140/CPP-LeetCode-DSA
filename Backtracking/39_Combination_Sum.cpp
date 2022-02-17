class Solution {
public:
    set<vector<int>> sv;
    vector<int> tmp;
    int n;
    void solve(int tar, vector<int>& nums, int i)
    {
        if(tar < 0 or i > n) return;
        if(tar == 0)
        {
            sv.insert(tmp);
            return;
        }
        if(i == n)
        {
            if(tar == 0)
                sv.insert(tmp);
            return;
        }
        
        tmp.push_back(nums[i]);
        tar -= nums[i];
        solve(tar, nums, i);
        tmp.pop_back();   
        tar += nums[i];
        
        solve(tar, nums, i+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sv.clear();
        tmp.clear();
        n = nums.size();
        // sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        solve(target, nums, 0);
        for(auto it: sv)
        {
            ans.push_back(it);
        }
        return ans;
    }
};