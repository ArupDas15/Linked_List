class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int count =0;
        for(char c: s){
          while(i<t.length()){
              if(t[i]==c){
                  i++;
                  count++;
                  break;
              }
              else i++;
          }
      }  
     if(count==s.length())
         return true;
    else return false;
    }
};