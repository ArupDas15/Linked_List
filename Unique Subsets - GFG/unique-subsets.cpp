// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void solve(vector<int> arr,set<vector<int>> &arr_set, vector<int> ans){
        if(arr.size()==0){
            arr_set.insert(ans);
            return;
        }
        vector<int> ans1=ans;
        vector<int> ans2=ans;
        ans2.push_back(arr[0]);
        arr.erase(arr.begin()+0);
        solve(arr,arr_set,ans1);
        solve(arr,arr_set,ans2);
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {   set<vector<int>>  arr_set;
        vector<vector<int> > res;
        vector<int> ans;
        sort(arr.begin(),arr.end());
        solve(arr,arr_set, ans); 
        for(auto itr : arr_set){
            res.push_back(itr);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends