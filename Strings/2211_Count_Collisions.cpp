/*
Algorithms:
   -> ans = 0
   -> convert all substrings of "RL" type to "SS"
   -> for each "RL" add 2 to ans
   -> iterate in modified string
      - if 'R': increment r_ctr++ and make S_found(sf) = 0
      - if 'S': add r_ctr to ans, make r_ctr = 0, make sf = 1
      - if 'L': if(sf == 1) increment ans by 1
   -> return ans     
*/

class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n-1;  i++)
        {
            if(s[i] == 'R' and s[i+1] == 'L') 
            {
                ans += 2;
                s[i] = 'S';
                s[i+1] = 'S';
            }
        }
        
        int rct = 0, lct = 0, sf = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i] == 'R')
            {
                rct++;
                if(sf) sf = 0;
            }
            else if(s[i] == 'S')
            {
                ans += rct;
                rct = 0;
                sf = 1;
            }
            else if(s[i] == 'L')
            {
                if(sf) ans++;
            }
        }
        
        return ans;
    }
};