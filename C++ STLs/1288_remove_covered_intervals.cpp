/*
Tip:
- Sort the vector pair in ascending order 
- If the first parameter is same, then sort in decreasing order
- comparator + STL
*/

class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if(a.first != b.first){
            if(a.first > b.first) return true;
            return false;
        }else{
            if(a.second < b.second) return true;
            return false;
        }
    }
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        vector<pair<int, int>> vp;
        for(auto it: nums)
        {
            vp.push_back({it[0], it[1]});
        }

        sort(vp.begin(), vp.end(), comp);
        reverse(vp.begin(), vp.end());
        
        int l = 0;
        int ans = 0;
        
        for(auto it: vp)
        {
            if(it.second > l)
            {
                ans++;
                l = it.second;
            }
        }
        return ans;
    }
};