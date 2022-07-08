class Solution {
public:
    string minWindow(string s, string t) {
        if(t==""){
            return "";
        }
        unordered_map<char,int> um;
        for(int i=0;i<t.length();i++){
            um[t[i]]++;
        }
        int need = um.size();
        unordered_map <char,int> window;
        int have = 0 ;
        int minLen = INT_MAX;
        int min_pos = -1;
        int i = 0; // start index of the window.
        int j = 0; //end index of the window.
        char c;
        string ans="";
        while(j < s.length()){
            c = s[j];
            window[c]++;
            
            if(um.find(c)!=um.end()&&window[c]==um[c])
                have ++;
            
            while(have == need){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    min_pos = i;
                }
                // Remove unncessary characters from the front of the sliding window.
                window[s[i]]--;
                if (um.find(s[i]) != um.end() && window[s[i]] < um[s[i]])
                    have--;
                // Slide the window to the right.
                i++;
            }
            j++;
        }
        if(minLen<INT_MAX)
            ans = s.substr(min_pos,minLen);
        return ans;
    }
};