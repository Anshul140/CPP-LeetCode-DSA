/*
Algorithm:
   -> Base Cases:
      - if pattern is of form pat[0] = pat[1]
        - count total #of pat[0] in text(ct), add 1 to the obtained number(ct++)
        - return (ct*(ct-1)/2)
      - no occurence of pat[0] and pat[1] in text, return 0
      - if only one of the char of pattern is present in text(either pat[0] or pat[1] is only present)
        - return the count of the that character(pat[0] or pat[1]) in text
   -> Case when both characters of pattern are present in text:
      case 1: add pat[0] at the beginning of text
        - keep a counter(ct) variable for occurence of pat[0] before certain pat[1] in text
        - start iteratiion on text
        - whenever pat[0] is encountered, increase the counter 
        - whenever pat[1] is encountered, add counter to the ans1

      - remove front pat[0] from text 
      - append pat[1] at the end of text

      case 2: add pat[1] at end of text
        - repeat same steps as in case 1
        - store the ans in ans2 variable

      finally return max(ans1, ans2)
*/

class Solution {
public:
    long long maximumSubsequenceCount(string txt, string pat) {
        map<char, long long> mp;
        char c1 = pat[0], c2 = pat[1];
        if(c1 == c2)
        {
            long long ct = 1, ans = 0;
            for(char ch: txt)
            {
                if(ch == c1) ct++;
            }
            
            ans = (ct*(ct-1))/2;
            return ans;
        }
        
        for(char ch: txt)
        {
            if(ch == c1 or ch == c2) mp[ch]++;
        }
        
        if(mp.size() == 0) return 0;
        if(mp.size() == 1)
        {
            long long ans = 0;
            for(auto it: mp) ans = max(ans, it.second);
            
            return ans;
        }
        
        long long ans1 = 0, ans2 = 0;
        string s1;
        for(char ch: txt)
        {
            if(ch == c1 or ch == c2) s1.push_back(ch);
        }
        s1.push_back(c2);
        long long ct1 = 0;
        for(char ch: s1)
        {
            if(ch == c1) ct1++;
            else if(ch == c2)
            {
                ans1 += ct1;
            }
        }
        
        s1.pop_back();
        s1.insert(0, 1, c1);
        ct1 = 0;
        for(char ch: s1)
        {
            if(ch == c1) ct1++;
            else ans2 += ct1;
        }
        
        return max(ans1, ans2);
    }
};