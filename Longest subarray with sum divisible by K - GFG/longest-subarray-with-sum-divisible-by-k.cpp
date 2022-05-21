// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Reference: https://www.youtube.com/watch?v=GrV3MTR_Uk0
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0;
	    int ans=0;
	    int rem=0;
	    int idx;
	    unordered_map<int,int>umap;
	    umap[0]=-1;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	        rem = sum % k;
	        if(rem<0){
	            rem = rem + k;
	        }
	        if(umap.find(rem)!=umap.end()){
	            idx = umap[rem];
	            if(ans<i-idx){
	                ans = i-idx;
	            }
	        }
	        else{
	            umap[rem]=i;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends
