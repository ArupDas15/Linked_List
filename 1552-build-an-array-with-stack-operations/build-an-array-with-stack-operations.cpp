class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j = 0;
        for(int i= 1; i < n+1 && j<target.size(); i++) {
            if(target[j]==i){
                // this if constraint works because target is trictly increasing
                ans.push_back("Push");
                j++;
            }else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
