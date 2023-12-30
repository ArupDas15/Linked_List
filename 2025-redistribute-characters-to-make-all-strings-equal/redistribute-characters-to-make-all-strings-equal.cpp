class Solution {
public:
    // Time Complexity: O(nk) - k is the average length of the elements in words
    // Space Complexity: O(1)
    bool makeEqual(vector<string>& words) {
        int arr[26] = {0};

        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                arr[c - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] % words.size() != 0)
                return false;
        }
        return true;
    }
};