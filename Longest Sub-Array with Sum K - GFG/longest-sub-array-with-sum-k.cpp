// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int N, int k) 
    { // Hash table to store (sum,index) pair.
        unordered_map<int,int> um;
        int j=0,maxLen=0;
        int sum=0;
        while(j<N){
            sum = sum + nums[j];
            if(um.find(sum)==um.end()){
                um[sum]=j;
            }
            if(sum!=k){
                if(um.find(sum-k)!=um.end()){
                    maxLen=max(maxLen,j-um[sum-k]);
                }
                j++;
            }
            else if(sum==k){
                maxLen = j + 1;
                j++;
            }
            
        }
        return maxLen;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends