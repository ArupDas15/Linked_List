class Solution {
public:
    string compressedString(string word) {
        std::ostringstream comp;  // Use ostringstream for efficient string building
        int n = word.length();

        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int count = 0;

            // Count consecutive characters
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }

            comp << count;          // Append the count to the stream
            comp << currentChar;    // Append the character to the stream
        }
        
        return comp.str();  // Convert the stream to string
    }
};