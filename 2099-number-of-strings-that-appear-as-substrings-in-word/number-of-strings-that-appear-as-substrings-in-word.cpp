class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto subStr : patterns)
        if (word.find(subStr) != std::string::npos) cnt++;
        return cnt;
    }
};