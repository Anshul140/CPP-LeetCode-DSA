/*
Algorithm:

1- Convert all odd into nums[i]*2
2- Insert all elements of nums into a set of decreasing order
3- Initalize diff = (set->1st element - set->last-element)
4- until the greatest element(x) of set becomes odd, erase it and insert (x/2)
    - also update difference in each iteration diff = min(diff, set.begin - set.rbegin)
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int diff;
        set<int, greater<int>> st;
        for(int i=0;i<n; i++)
        {
            if(nums[i] & 1) nums[i] *= 2;
            st.insert(nums[i]);
        }
        
        diff = *st.begin() - *st.rbegin();
        while(!(*st.begin() & 1))
        {
            int x = *st.begin();
            st.erase(st.begin());
            st.insert(x/2);  
            diff = min(diff, abs(*st.begin() - *st.rbegin()));
        }
        
        return diff;
    }
};