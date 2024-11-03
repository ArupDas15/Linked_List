class Solution {
public:
    bool rotateString(string s, string goal) {
        string newgoal = goal + goal;
        return ((s.length() == goal.length()) and 
                (newgoal.find(s) != std::string::npos));
    }
};