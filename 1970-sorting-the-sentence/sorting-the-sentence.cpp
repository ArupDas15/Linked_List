class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(n)
    string sortSentence(string s) {
        string arr[9];
        string temp = "";
        
        for(int i = 0; i < 9; i++) {
            arr[i] = "";
        }
        for(char c : s) {
            if(c != ' ' ) {
                if(isdigit(c)) {
                    arr[c - '0' - 1] = temp;
                    temp = "";
                } else {
                    temp.push_back(c);
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            if(arr[i] != "") {
                temp = temp + arr[i];
                if(i + 1 < 9 and arr[i + 1] != "") {
                    temp = temp + " ";
                }
            }
        }
        return temp;
    }
};