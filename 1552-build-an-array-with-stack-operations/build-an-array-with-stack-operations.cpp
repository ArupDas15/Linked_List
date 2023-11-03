class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        vector<string> ans;
        
        for(int i= 1; i < n+1 && j<target.size(); i++) {
            if(target[j]==i){
                // this if constraint works because the target is strictly increasing
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
