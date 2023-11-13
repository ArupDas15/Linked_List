class Solution {
public:
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