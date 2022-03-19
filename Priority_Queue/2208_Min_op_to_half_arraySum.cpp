/*
Algorithm:
   -> store each element of nums in max heap priority_queue(pq)
   -> keep temp = 0, sum = sum(nums[i])
   -> while (temp < sum/2.0):
      - take top element(curr) and pop it
      - temp += curr/2.0
      - pq.push(curr/2.0)
      - increase the counter of operation(ans++)
   -> return ans   
*/

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0.0;
        int ans = 0;
        priority_queue<double> pq;
        
        for(int el: nums)
        {
            pq.push(el);
            sum += el;
        }
        
        double temp = 0;
        while(temp < (sum/2.0))
        {
            double curr = pq.top();
            pq.pop();
            
            temp += curr/2.0;
            pq.push(curr/2.0);
            ans++;
        }
        
        return ans;
    }
};