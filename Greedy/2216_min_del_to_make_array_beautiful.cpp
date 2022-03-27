/*
Algorithm:
   -> base cases: n == 1: return 1,
                  n == 2: return nums[0] == nums[1] ? 2: 0;
   -> ans = 0, start_idx(si) = 0, ct = 0
   -> start iterating from 1st index
      - if nums[i] equals nums[i-1]: increment ct
      - else:
           - if start_idx(si) is even: increment ans by ct, make si = 1
           - else if si is odd: increment ans by max(ct-1, 0), if(ct == 0) make si = 0
           - make ct = 0
   -> outside loop: if(ct > 0):
         - if si even: ans += ct
         - else ans += max(ct-1, 0)
   -> if (n-ans) is odd increment ans
   -> return ans                          
*/     

int minDeletion(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return nums[0] == nums[1]?2: 0;
        
        int ans = 0, si = 0;
        
        int ct = 0;
        for(int i = 1; i<n; i++)
        {
            if(nums[i] == nums[i-1])
                ct++;
            else
            {
                // cout<<"i: "<<i<<" ct: "<<ct<<endl;
                if(si == 0)
                {
                    ans += ct;
                    si = 1;
                }   
                else if(si == 1)
                {
                    ans += max(ct-1, 0);
                    if(ct == 0)
                        si = 0;
                } 
                ct = 0;
            }
        }
        if(ct > 0)
        {
            if(si == 0) ans += ct;
            else ans += max(ct-1, 0);
        }    
        
        if((n - ans) & 1)
            ans++;
        return ans;
    }