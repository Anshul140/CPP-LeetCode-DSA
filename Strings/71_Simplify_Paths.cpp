/*
1-
    IP: "/home//foo/"
    OP: "/home/foo"

2-
    IP: "/a/./b/../../c"
    OP: "/c"
Explaination:
    [home] (/a --> means go inside folder a)     [a]
    [a] (/. --> means stay on same directory)    [a]
    [a] (/b --> means go inside folder b)        [b]
    [b] (/.. --> go outside current directory)   [a]
    [a] (/.. --> go outside current directory)   [home]
    [home] (/c means go inside folder c)         [c]

    hence the final output is: "/c"

3-
    IP: "/../"
    OP: "/"
    since we can't go outside root directory(invalid operation), OP is "/"  
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vs;
        string ans = "";
        
        for(int i = 0; i<path.length(); i++)
        {
            string curr = "";
            while(i < path.length() and path[i] != '/') curr += path[i++];
            
            if(curr == "" or curr == ".") continue;
            else if(curr == "..") {if(vs.size() > 0) vs.pop_back();}
            else vs.push_back(curr);
        }
        
        for(int i = 0; i<vs.size(); i++) ans += "/" + vs[i];
        
        if(ans.size() == 0) return "/";
        return ans;
    }
};