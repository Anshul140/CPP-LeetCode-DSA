/*
Algorithm:
   -> just sorting on the basis of 1st or 2nd parameter won't work because
      it will not give optimum value
   -> actual parameter is how much we benefit if we choose to go say city A than B
   -> sort the vector pair on the basis of difference of (second-el)-(first-el)
   -> e.g. i/p: [[10,20],[30,200],[400,50],[30,20]]
                    A   B 
   -> sorted vp:   30  200 -> 170 -> choose A
                   10  20  -> 10  -> choose A
                   30  20  -> -10 -> choose B
                   400  50 -> -350 -> choose B
*/
class Solution {
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        return (p2.second-p2.first) < (p1.second - p1.first);  
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        
        vector<pair<int, int>> vp;
        for(int i = 0; i<costs.size(); i++)
        {
            vp.push_back({costs[i][0], costs[i][1]});
        }
        
        int sz = vp.size();
        sort(vp.begin(), vp.end(), comp);
        
        for(int i = 0; i<sz; i++)
        {
            // cout<<vp[i].first<<"  "<<vp[i].second<<endl;
            if(i < sz/2) ans += vp[i].first;
            else ans += vp[i].second;
        }
        // cout<<endl;
        
        return ans;
    }
};