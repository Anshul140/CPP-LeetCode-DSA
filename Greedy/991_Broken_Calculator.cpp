/*
Algorithm:
   -> ans = 0
   -> base condition: if final <= start: return start-final
   -> while(final > start):
         - if(final & 1): final += 1, ans++
         - else: final /= 2, ans++
   -> at last ans += (start - final)      
*/

class Solution {
public:
    int brokenCalc(int start, int fin) {
        if(fin <= start)
            return start-fin;
        
        int ans = 0;
        while(fin > start)
        {
            if(fin % 2 == 0)
            {
                fin /= 2;
                ans++;
            }
            else
            {
                fin += 1;
                ans++;
            }
        }
        
        ans += start - fin;
        return ans;
    }
};