/*
STL used:
   -> unique()
   -> used to remove duplicates of any element present consecutively in a range
*/


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        auto it = unique(nums.begin(), nums.begin()+n);
        
        nums.resize(distance(nums.begin(), it));
        n = nums.size();
        int ans = 0;
        for(int i = 1; i<n-1; i++)
        {
            if(nums[i] > nums[i-1] and nums[i] > nums[i+1]) ans++;
            else if(nums[i] < nums[i-1] and nums[i] < nums[i+1]) ans++;
        }
        
        return ans;
    }
};