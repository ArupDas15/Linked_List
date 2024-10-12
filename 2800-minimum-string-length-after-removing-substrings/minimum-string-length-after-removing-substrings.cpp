class Solution {
public:
    /* STEPS
    1. Iterste until string.find("AB") or string.find("CD") is not -1.
        1. Replace string.replace(string.find("AB"),"AB",1,"")
        2. Replace string.replace(string.find("CD"),"CD",1,"")
    2. Return string.length()
    */
    int minLength(string s) {
        while(s.find("AB") != -1 or s.find("CD") != -1) {
            if(s.find("AB") != -1) {
                s.erase(s.find("AB"), 2);
            }
            if(s.find("CD") != -1) {
                s.erase(s.find("CD"), 2);
            }
        }
        return s.length();
    }
};