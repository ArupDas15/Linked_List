class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int num : arr) {
            if ((s.find(2*num) != s.end()) or 
                ((num%2 == 0) && 
                (s.find(num/2) != s.end()))) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};