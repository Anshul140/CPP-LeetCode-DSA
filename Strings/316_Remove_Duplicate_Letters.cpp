/*
Algorithm:
   -> keep 2 arrays last(26), vis(26)
       last(26): for last occurence of a character
       vis(26): to keep track of included characters for final string
   -> start iterating on input string:
       at each iteration: 
          -check if(vis(s[i])) continue
          -while(string not empty && ans-string last char > s[i] and last[ans.back()] > i)
              -mark vis for ans.back false
              -pop out ans.back
          -insert s[i] to ans string
          -mark s[i] visited true             
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> vis(26), last(26);
        
        for(int i = 0; i<s.length(); i++) last[s[i] - 'a'] = i;
        
        for(int i = 0; i<s.length(); i++)
        {
            if(vis[s[i] - 'a']) continue;
            
            while(!ans.empty() and ans.back() > s[i] and last[ans.back() - 'a'] > i)
            {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        
        return ans;
    }
};