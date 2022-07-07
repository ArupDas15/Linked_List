class Solution {
public:
    // Reference Aditya Varma - Variable Sliding Window: https://www.youtube.com/watch?v=L6cffskouPQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=11
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
//Alternate Solution
/*
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
*/
