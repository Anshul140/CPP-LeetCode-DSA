#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vl vector<ll>
#define Map map<ll, ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define PYes cout<<"YES\n"
#define PNo cout<<"NO\n"
#define fl(i, a, b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

string removeKdigits(string num, int k) {
    int ct = 0, n = num.size();
    if(k == n) return "0";

    stack<int> st;
    string ans = "";
    int j = 0;

    while(j < n) {
        if(st.empty())
        {
            if(num[j] != '0')
                st.push(num[j] - '0');
        }       
        else if(st.top() > (num[j]-'0') and ct < k)
        {
            while(!st.empty() and st.top() > (num[j] - '0') and ct < k)
            {
                ct++;
                st.pop();
            }
            if(st.empty() and num[j] == '0')
                continue;
            else
                st.push((num[j] - '0'));
        }
        else
        {
            st.push(num[j] - '0');
        }
        j++;
    }
    
    while(!st.empty() and ct < k)
    {
        st.pop();
        ct++;
    }

    while(!st.empty())
    {
        int x = st.top();
        ans.push_back((x + '0'));
        // cout<<st.top()<<" ";
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    
    while(ans[0] == '0')
        ans.erase(0, 1);
    
    return ans == ""? "0": ans;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string num;
    int k;
    cin>>num;
    cin>>k;

    cout<<removeKdigits(num, k)<<endl;
    
    return 0;
}