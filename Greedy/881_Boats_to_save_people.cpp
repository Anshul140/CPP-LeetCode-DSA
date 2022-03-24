/*
Algorithm:
   -> sort the array
   -> keep two pointers i = 0 and j = n-1
   -> while (i <= j):
      - if(nums[i] + nums[j] <= limit): ans++, j--, i++
      - else: ans++, j--
   -> return ans     

*/

class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(),ans = 0,i = 0, j = n-1;
        while(i <= j)
        {
            if(nums[j] + nums[i] <= limit)
            {
                ans += 1;
                i++;
                j--;
            } 
            else {
                ans += 1;
                j--;
            }
        }
        
        return ans;
    }
};