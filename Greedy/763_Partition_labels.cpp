/*
Algorithm:
   -> keep track of last index of every char in string in map(mp)
   -> keep two pointers, maxi = 0 , prev = -1
   -> start iterating in string(s)
      - at each iteration update maxi = max(maxi, mp[s[i]])
      - if (i == maxi) :
          - push (i- prev) in ans array, (i - prev) is length of segment
          - update prev = i
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26);
        
        for(int i = 0; i<s.length(); i++)
            mp[s[i] - 'a'] = i;
        vector<int> ans;
        int maxi = 0;
        int prev = -1;
        
        for(int i = 0; i<s.length(); i++)
        {
            maxi = max(mp[s[i] - 'a'], maxi);
            if(i == maxi)
            {
                ans.push_back(i - prev);
                prev = i;
            }    
        }
        
        return ans;
    }
};