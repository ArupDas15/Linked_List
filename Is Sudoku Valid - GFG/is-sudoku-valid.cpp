// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        unordered_set<string> seen;
        string key;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9 ; j++){
                if(mat[i][j]!=0){
                    key = to_string(mat[i][j])+ std::string(" found in row ")+to_string(i);
                    if(seen.find(key) == seen.end()){
                        seen.insert(key);
                    }
                    else 
                        return false;
                    key = to_string(mat[i][j])+ std::string(" found in column ")+to_string(j);
                    if(seen.find(key) == seen.end()){
                        seen.insert(key);
                    }
                    else 
                        return false;
                    key = to_string(mat[i][j])+ std::string(" found in box ")+to_string(i/3)+to_string(j/3);
                    if(seen.find(key) == seen.end()){
                        seen.insert(key);
                    }
                    else 
                        return false;
                }
                
            }
        } 
        return true;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends