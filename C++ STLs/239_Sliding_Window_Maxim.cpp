/*
Algorithm:
   -> Inorder to keep track of max of all subarray of size k,
      DS with properties of pop/push at both front and back is required
   -> can be done using list/deque STL
   -> iterate through whole array
   -> every iteration: insert current array element before popping out all smaller elements in dq   
   -> this will ensure max element at front
   -> above steps with sliding window algorithm
   -> if window size is hit: 
      - insert the front of dq in ans array,
      - then check if front of dq is also the same element to be removed from window
      - if yes, then pop_front it 
      - i++, j++ 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        
        int i = 0, j = 0;
        while(j < n)
        {      
            while(!dq.empty() and dq.back() < nums[j])
                dq.pop_back();
            dq.push_back(nums[j]);
            
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k)
            {
                ans.push_back(dq.front());
                if(dq.front() == nums[i])
                    dq.pop_front(); 
                i++;
                j++;
            }
        }
        
        return ans;
    }
};