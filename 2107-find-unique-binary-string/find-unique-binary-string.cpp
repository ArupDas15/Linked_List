class Solution {
public:
    set<string>numset;
    string generate(string curr) {
        if(curr.length() == numset.size()) {
            if(numset.find(curr) == numset.end()) {
                return curr;
            }
            return "";
        }
        string zero_str = generate(curr + "0");
        if(zero_str != "") {
            return zero_str;
        }
        return generate(curr + "1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            numset.insert(nums[i]);
        }
        return generate("");
    }
};