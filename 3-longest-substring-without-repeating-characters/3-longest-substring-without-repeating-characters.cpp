class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;// start index of window.
        int j=0;// end index of window.
        unordered_map<char,int> um;
        int maxLen=0;// to store the ans
        while(j<s.length()){
            um[s[j]]++;
            // Check if all the characters in the window are unique.
            // This will happen only when size of the window and the map are equal.
            if(um.size()==j-i+1){
                maxLen = max(maxLen, j-i+1);
            }
            else if(um.size()<j-i+1){
                while(um.size()<j-i+1){
                    um[s[i]]--;
                    if(um[s[i]]==0)
                        um.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};