/* 
  Minimum sum partition - Hard - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
  
  Given an array arr of size N containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference.

  Example 1:

	Input: N = 4, arr[] = {1, 6, 11, 5} 
	Output: 1
	Explanation: 
	Subset1 = {1, 5, 6}, sum of Subset1 = 12 
	Subset2 = {11}, sum of Subset2 = 11 

  Example 2:
	Input: N = 2, arr[] = {1, 4}
	Output: 3
	Explanation: 
	Subset1 = {1}, sum of Subset1 = 1
	Subset2 = {4}, sum of Subset2 = 4

  Your Task:  
	You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value


   Expected Time Complexity: O(N*|sum of array elements|)
   Expected Auxiliary Space: O(N*|sum of array elements|)


  Constraints:
  	1 ≤ N*|sum of array elements| ≤ 106

  	The array contains non-negative integers.

  Solution Explanation: https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10

*/
#include<bits/stdc++.h>
using namespace std; 

class Solution{

  public:
    vector<int> subsetSum(int arr[],int n, int Range){
        int t[n + 1][(Range/2) + 1];
        vector<int> s1_candidates;
        
        for(int i = 0; i < (Range/2) + 1; i++){
            t[0][i] = false;
        }
        for(int i = 0;i < n + 1; i++){
            t[i][0] = true;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < (Range/2) + 1 ;j++){
                if(arr[i - 1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        for(int i = 0; i < (Range/2) + 1; i++){
            if(t[n][i] == true)
            s1_candidates.push_back(i);
        }
        return s1_candidates;
    }
	int minDifference(int arr[], int n)  { 
	    int Range = 0;
	    for(int i = 0; i < n; i++){
	        Range = Range + arr[i];
	    }
	    // Find all the possible candidates for the sum of elements in Subset S1.
	    vector<int> s1_candidates = subsetSum(arr, n, Range);
	    int ans = INT_MAX;
	    // Find the minimum sum partition.
	    for(int i = 0; i < s1_candidates.size(); i++){
	        ans = min( ans, Range - (2*s1_candidates[i]));
	    }
	    return ans;
	} 
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		Solution ob;
		cout << ob.minDifference(a, n) << "\n" ;
	}
	return 0;
}
