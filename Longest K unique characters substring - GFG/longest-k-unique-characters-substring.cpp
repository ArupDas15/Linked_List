// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
     if(k>s.length())
        return -1;
     unordered_map<char,int>um;
     string input=s;
     int count=0;
     int maxLen=-1;
     int i=0; // start index of the sliding window.
     int j=0; // end index of the sliding window.
     // Convert input string to lowercase. 
     transform(input.begin(), input.end(), input.begin(), ::tolower);
     while(j<input.length()){
         // If the character has been encountered for the first time or frequency of the character in the current sliding window is zero.
         if(um.find(input[j])==um.end()||um[input[j]]==0){
             count++;
         }
         um[input[j]]++;
         if(count==k){
             maxLen=max(maxLen,j-i+1);
         }
         while(count>k){
             if(um[input[i]]==1){
                 count--;
             }
             um[input[i]]--;
             i++;
         } // End of while-loop.
         j++;
         
     }// End of for-loop
     return maxLen;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends
