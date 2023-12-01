class Solution {
public:
    // Time Complexity: O(nk) where k is the maximum length of the string in the string vector.
    // Space Complexity: O(nk)
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";

        for(string s : word1) {
            s1 = s1 + s;
        }
        for(string s : word2) {
            s2 = s2 + s;
        }
        return s1 == s2;
    }
};
