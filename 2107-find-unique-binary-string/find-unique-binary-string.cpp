class Solution {
public:
    // Cantor's Diagonal Argument: https://en.wikipedia.org/wiki/Cantor%27s_diagonal_argument
    // Time complexity: O(n)
    // Space complexity: O(1)
    string findDifferentBinaryString(vector<string>& nums) {
        string curr = "";
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i][i] == '0') {
                curr = curr + "1";
            } else {
                curr = curr + "0";
            }
        }
        return curr;
    }
};

/*
// Time complexity: O(n^2)
// space complexity: O(n)
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
*/