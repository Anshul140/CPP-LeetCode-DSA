// count set bits from 0 to n
/*
Approach 1:
   -> taking '&' of every bit with 1 and keep track of count 
Approach 2:
   -> using STL __builtin_popcount(i)
*/

int countSetBits(int n)
{
    int ct = 0;
    for(int i = 31; i>=0; i--){
        if((n & (1<<i)) != 0)
            ct++;
    }
    
    return ct;
}
vector<int> countBits(int n) {
    vector<int> ans;
    
    for(int i = 0; i<=n; i++)
    {
        ans.push_back(countSetBits(i));
        //  ans.push_back(__builtin_popcount(i));
    }
    
    return ans;
}