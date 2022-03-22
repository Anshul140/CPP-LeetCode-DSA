/*
ALGORITHM

    -> Initialise an string of length n with all 'a's.
    -> Start traversing from the end of the string and add the element of the string by 'z' if k >= 25. as a is already inserted with ascii 1 , adding 25 to 1 result in 26 i.e 'z'.
    -> At the same time decrease the value of K by replaced element value i.e. for a = 1, b = 2, c = 3, …, z = 26.
    -> Check for K < 0 condition and break the for loop.
    -> Return the new string formed.
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        
        k -= n;
        
        while(k > 0)
        {
            ans[--n] += min(25, k);
            k -= min(25, k);
        }
        
        return ans;
    }
};