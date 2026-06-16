class Solution {
public:
    
    string processStr(string s) {
       string ans;
       
       for(char ch : s) {
            if(islower(ch)) {
                ans.push_back(ch);
            } else if (ch=='#') {
                ans=ans+ans;
            } else if (ch=='%'){
                reverse(ans.begin(),ans.end());
            } else if (ch=='*') {// remove last character
                if (!ans.empty())
                ans.pop_back();
            }
       } 
       return ans;
    }
};