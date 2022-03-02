// check if s1 is subsequence of s2 or not

bool isSubsequence(string s1, string s2) {
    if(s1 == s2) return true;
    int n1 = s1.size(), n2 = s2.size();
    
    int i = 0, j = 0;
    if(n1 > n2) return false;
    
    while(i < n1 and j < n2)
    {
        if(s1[i] == s2[j]) 
            i++, j++;
        else
            j++;
    }
    return i == n1;
}