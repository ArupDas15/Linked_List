class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> mp;
        string ans = "";
        
        for(vector<string> path : paths) {
            string source = path[0];
            string dest = path[1];

            mp[source] = true;
            if(mp.find(dest) == mp.end()) {
                mp[dest] = false;
            } else {
                mp[dest] = true;
            }
        }
        for(auto i : mp) {
            if(i.second == false) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};