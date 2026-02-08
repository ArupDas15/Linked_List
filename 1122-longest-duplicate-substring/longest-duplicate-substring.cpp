class Solution {
public:
    /* Conditions for returning the longest duplicate substring.
    1. Substrings can be overlapping.
    2. Atleast 1 character should be non-overlapping.
    3. Return any string of max_length.
    
    There are 3 approaches to solve this problem. 
    1. Ukkonen's suffix tree. 
        Variant of Longest Common Substring.
        Time Complexity: O(n)
        We cannot apply LCS here because 
        Total space allocated to the dp table will be 
        (3*10^4) * (3*10^4) * 4B per integer = 3.6GB 
        A DP-based Longest Common Substring approach 
        is infeasible because it requires an O(n²) table. 
        For n = 3×10⁴, this would require ~3.6 GB of memory, 
        which is impractical.
    2. Trie + Binary Search
        Time Complexity: 
        Binary search on the answer length k (from 1 to n) 
        + No. of substrings of given length K (n − k + 1 ≈ O(n) substrings; when k = 1)
        + Traverse a substring & insert in Trie.
        = O(log N * N * k)
        In worst case, Binary search will try values of k up to n:
         O(n² log n) = 9×10⁸ × log n operations
    3. Rolling Hash (Rabin Karp) + Binary Search
        Binary Search on length of largest duplicate substring.
        Use rolling hash to find a pattern.
        We need to use a stronger hash to minimise 
        number of collisions (in this case false duplicates such as anagrams).
    */
    #define p 10000007
    bool match(string s, int len, int size, string& ans, vector<int>& roll) {
        // map: <hash_value, start_position_of_duplicate_string>
        unordered_map<int, vector<int>> m;
        int hash = 0;   //curr window hash
        for(int i=0; i < size; i++) {
            hash=(hash*26+(s[i] - 'a'))%p;
        }
        m[hash].push_back(0);
        //Rolling hash (sliding window)
        for(int j=size;j<len;j++){
            hash=((hash-roll[size-1]*(s[j-size]-'a'))%p+p)%p;
            hash=(hash*26+(s[j]-'a'))%p;
            if(m.find(hash)!=m.end()){
                for(auto start:m[hash]) {
                    string temp = s.substr(start,size);
                    string curr = s.substr(j-size+1,size);
                    if(temp.compare(curr) == 0) {
                        ans = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j-size+1);
        }
        return false;
    }
    string longestDupSubstring(string s) {
        int len = s.length();
        if (len == 0) return "";
        // create a rolling hash utility array.
        vector<int> roll(len);
        roll[0]= 1; // store 26^0 = 1.
        for(int i = 1; i < len; i++)
            roll[i] = (26*roll[i-1])%p;
    
        int low = 1, high = len, mid;
        string ans = "", temp;
        while(low<=high) {
            temp ="";
            mid=low+(high-low)/2;
            bool flag = match(s, len, mid, temp, roll);
            if(flag) {
                if(temp.size()>ans.size()) {
                    ans = temp;
                }
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};