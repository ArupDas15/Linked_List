class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        sort(s1.begin(), s1.end());cout<<s1<<endl;
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            string tmp = s2.substr(i,s1.length());
            sort(tmp.begin(),tmp.end());
            if (s1.compare(tmp) == 0) {
                return true;
            }
        }
        return false;
    }
};