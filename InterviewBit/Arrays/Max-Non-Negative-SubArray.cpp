/*
Max Non Negative SubArray: Easy : https://www.interviewbit.com/problems/max-non-negative-subarray/

Problem Description

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:  

If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.


Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
The first and the only argument of input contains an integer array A, of length N.



Output Format
Return an array of integers, that is a subarray of A that satisfies the given conditions.



Example Input
Input 1:

 A = [1, 2, 5, -7, 2, 3]
Input 2:

 A = [10, -1, 2, 3, -4, 100]


Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [100]


Example Explanation
Explanation 1:

 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3].
Explanation 2:

 The three sub-arrays are [10], [2, 3], [100].
 The answer is [100] as its sum is larger than the other two.


Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

*/
/* 
-------------------------
Solution Approach
-------------------------
Here we go :

Loop i = 1 to Array.length :
        IF current element is positive :
                update current sum
                compare max sum with current sum
                update max sum
                update max ranges
        ELSE :
            current sum := 0
            update current ranges.
EndLoop;

return elements of max range
*/
// Time Complexity: O(n)
vector<int> Solution::maxset(vector<int> &A) {
    // We use long long int to avoid overflow problems that would occur when adding two large int variables.
    long long int sum= 0 , max_sum=INT_MIN;
    int i = 0, j =0,startindex,mini_len=INT_MIN;
    vector<int>ans;
    while(j<A.size()){
        // IF current element is non-negative
        if(A[j]>=0){
            // update the current sum.
            sum=sum+A[j];
            // update maximum sum if current sum is greater than maximum sum
            if(max_sum<sum){
                max_sum=sum;
                startindex=i;
                mini_len=j-i+1;
            }
            //If maximum sum == current sum, then compare with segment's length and return segment which has maximum length.
            //If there is still a tie, then the segment with minimum starting index will be returned because we are starting from i=0.
            else if(max_sum==sum && mini_len<j-i+1)
                startindex = i;
                mini_len=j-i+1;
            }
            j++;
        }
        else{
            sum = 0;
            while(A[j]<0){
                j++;
                i=j;
            }
        }
    }
    for(int i = 0;i<mini_len;i++)
        ans.push_back(A[startindex+i]);
    
    return ans;
}
