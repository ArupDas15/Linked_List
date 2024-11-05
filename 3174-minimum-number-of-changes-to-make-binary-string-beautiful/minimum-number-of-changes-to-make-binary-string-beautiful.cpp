class Solution {
public:
    // Time Complexity: O(n/2) ~ O(n)
    // Space Complexity: O(1)
    /*  ---------------------------------------------------------------------------------
        We can make the implementation much more concise by making a
        key observation: any even-length sequence can be split into 
        pairs of two characters. This is the smallest valid even sequence 
        we can have. 
        we can decompose the whole string into disjoint blocks of size 2 
        and find the minimum number of changes required to make those blocks beautiful.
        ---------------------------------------------------------------------------------
    */
    int minChanges(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i+=2) {
            if (s[i] != s[i+1]) {
                count++;
            }
        }
        return count;
    }
};
