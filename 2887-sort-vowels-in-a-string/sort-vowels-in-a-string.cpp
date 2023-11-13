class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Returns true if the character is a vowel.
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    
    string sortVowels(string s) {
        int j = 0;
        string sorted_vowel = "AEIOUaeiou";
        string t;
        unordered_map<char, int> mp;

        for(char c: s) {
            if(isVowel(c)) {
                mp[c]++;
            }
        }
        for(int i = 0; i < s.size(); i++) {
            if(!isVowel(s[i])) {
                t.push_back(s[i]);
            } else {
                while(mp[sorted_vowel[j]] == 0) {
                    j++;
                }
                t.push_back(sorted_vowel[j]);
                mp[sorted_vowel[j]]--;
            }
        }
        return t;
    }
};

/*
class Solution {
public:
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    string sortVowels(string s) {
        string t;
        vector<int> idxs;
        vector<char> s_vowels;
        set<char> vowels({'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'});

        for(int i = 0 ;i < s.length(); i++) {
            if(vowels.find(s[i]) == vowels.end()) {
                t.push_back(s[i]);
            } else {
                t.push_back('_');
                s_vowels.push_back(s[i]);
                idxs.push_back(i);
            }
        }
        sort(s_vowels.begin(),s_vowels.end());
        for(int i = 0; i < idxs.size(); i++) {
            t[idxs[i]] = s_vowels[i];
        }
        return t;
    }
};
*/
