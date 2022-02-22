int titleToNumber(string str) {
    int n = str.length();
    int p = 0;
    int ans = 0;
    for(int i = n-1; i>= 0; i--)
    {
        int pf = pow(26, p);
        int ch = str[i] - 'A' + 1;
        ans += pf*ch;
        p++;
    }
    
    return ans;
}