class Solution {
public:
    int minLength(string s) {
        string final_string;
        bool not_minimum = true;
        do {
            not_minimum = false;
            final_string.clear();
             for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D'))) {
                // Skip the next character as well
                not_minimum = true;  // We made a removal
                i++;  // Skip the current and the next character
            } else {
                final_string.push_back(s[i]);  // Keep the current character
            }
        }
        s = final_string;  // Update the string for the next iteration
        } while (not_minimum);
        return s.length();
    }
};