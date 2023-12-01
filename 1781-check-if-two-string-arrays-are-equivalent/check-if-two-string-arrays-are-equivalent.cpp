class Solution {
public:
    // Time Complexity: O(n) where k is the maximum length of the string in the string vector.
    // Space Complexity: O(1)
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wrd1Ptr, wrd2Ptr, str1Ptr, str2Ptr;

        wrd1Ptr = wrd2Ptr = str1Ptr = str2Ptr = 0;
        while (wrd1Ptr < word1.size() && wrd2Ptr < word2.size()) {
            if (word1[wrd1Ptr][str1Ptr++] != word2[wrd2Ptr][str2Ptr++]) {
                return false;
            }
            if (str1Ptr == word1[wrd1Ptr].size()) {
                wrd1Ptr++;
                str1Ptr = 0;
            }
            if (str2Ptr == word2[wrd2Ptr].size()) {
                wrd2Ptr++;
                str2Ptr = 0;
            } 
        }
        // checking if both string vectors have been traversed completely.
        return (wrd1Ptr == word1.size()) && (wrd2Ptr == word2.size());
    }
};