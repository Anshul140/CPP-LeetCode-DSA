/*
-Approach:
   -> using map, store count of each variable
   -> make vector pair of element and their count using maps
   -> sort vector pair based on count of elements in descending order
   -> store ans of size k, using vector pair
*/
class Solution {
public:
    static bool sortBySecond(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int el: nums) mp[el]++;
        
        vector<pair<int, int>> vp;
        
        for(auto it: mp)
        {
            vp.push_back({it.first, it.second});
        }
        
        sort(vp.begin(), vp.end(), sortBySecond);
        
        vector<int> ans;
        int ct = 0;
        for(auto it: vp)
        {
            // cout<<"f: "<<it.first<<" s: "<<it.second<<endl;
            if(ct < k)
            {
                ans.push_back(it.first);
                ct++;
            }
            else
                break;
        }
        
        return ans;
    }
};