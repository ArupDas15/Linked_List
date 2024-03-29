class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1): the input only contains lowercase English 
    // letters. Thus, the size of these hash maps never exceed 26, so we 
    // use O(1) space.
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> char_mp;
        
        for(char ch : chars) {
            char_mp[ch] += 1; 
        }
        for(int i = 0; i < words.size(); i++) {
            bool flag = true;
            string s = words[i];
            unordered_map<char, int> s_mp;
            
            if(s.length() > chars.length()) 
                continue;
            for(char ch : s) {
                s_mp[ch] += 1;
            }
            for(auto i : s_mp) {
                if( s_mp[i.first] <= char_mp[i.first]) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                ans = ans + s.length();
            }
        }
        return ans;
    }
};