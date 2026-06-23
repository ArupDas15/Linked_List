/*
You do not need the final string. You only need to know which character ends up at position k.

This usually suggests a forward pass to compute lengths and then a backward pass to map k back through the operations. 
Instead of constructing the string, ask:

"What position in the previous state produced this character?"

For each character:

lowercase → L + 1
# → 2L
* → max(0, L-1)
% → L

# → maps to an earlier position
% → maps to an earlier position
* → maps to an earlier position
letter → either returns that letter or maps to an earlier position

Storing the resulting string is expensive
The problem says:

The length of result after processing s will not exceed 10^15.

Imagine:

a##########

Every # doubles the string.
Lengths become:
The string length is at most:

10^5

characters in s.
Memory:

10^5 × 8 bytes ≈ 800 KB

which is tiny.
*/
class Solution {
public:
    char processStr(string s, long long k) {
        // The problem says the final result length can be as large as: 10^15
        // finalLength be the same type as k
        long long  finalLength = 0ll;
        vector<long long> len;

        for(char ch:s) {
            if ('a' <= ch and ch <= 'z') {
                finalLength += 1;
            } else if (ch == '*') {
                finalLength = max(0ll, finalLength-1);
            } else if (ch == '#') {
                finalLength *= 2;
            } else if (ch == '%') {
                // length unchanged
            }
            len.push_back(finalLength);
        }
        if (k >= finalLength) return '.';
        for (int i = s.length()-1; i >= 0; i--){
            /*
            i = position in the input string s
            k = position in the evolving result string
            When we trace backwards, we're asking: "Where did the character at position k come from?" => we're searching for the lowercase letter that originally created position k.
            */
            char ch = s[i];
            long long currLen = len[i];
            long long prevLen = (i == 0 ? 0ll: len[i-1]);
            if (ch == '#') {
                // It is possible to encounter a # whose previous length was zero while still tracing a valid final character
                if (prevLen > 0) k = k%prevLen;
            }
            else if (islower(ch)) {
                if (k == currLen-1) return ch;
                else {
                    // k remains unchanged
                }
            }
            else if (ch == '%') {
                k = currLen - k - 1;
            } else if (ch == '*') {
                // k remains unchanged
            }
        }
        return '.';
    }
};