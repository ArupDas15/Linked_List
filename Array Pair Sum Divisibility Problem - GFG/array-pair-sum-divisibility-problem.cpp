// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
    int rem;
    unordered_map<int,int> freq_count;
    if(arr.size()&1) return false;
    for(int i=0;i<arr.size();i++){
        rem = ((arr[i]%k)+k)%k;
        freq_count[rem]=freq_count[rem]+1;
    }
        for(auto i:arr){
            rem = ((i%k)+k)%k;
            if (rem==0&&((freq_count[rem]&1)==0)){
                continue;
            }
            
            else if (freq_count[k-rem]==freq_count[rem]){
                continue;
            }
            else{
                return false;
            }
        }
            
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends