class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    bool isCircularSentence(string sentence) {
        std::istringstream iss(sentence);
        vector<string> words;
        std::string word;

        while (iss >> word) {               // Extract words from the stream
            words.push_back(word);          // Add each word to the vector
        }
        int n = words.size();
        if (words[0][0] != words[n - 1].back()) {
            return false;
        }
         for (int i = 0; i < n - 1; i++) {
            if (words[i].back() != words[i + 1][0]) {
                return false;
            }
        }
        return true;

    }
};