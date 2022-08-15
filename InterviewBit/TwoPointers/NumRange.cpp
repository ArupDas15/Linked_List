/* 
NUMRANGE - EASY - https://www.interviewbit.com/problems/numrange/

Given an array of non negative integers A, and a range (B, C), 

find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C

Continuous subsequence is defined as all the numbers A[i], A[i + 1], .... A[j]

where 0 <= i <= j < size(A)

Example :

A : [10, 5, 1, 0, 2]
(B, C) : (6, 8)
ans = 3 

as [5, 1], [5, 1, 0], [5, 1, 0, 2] are the only 3 continuous subsequence with their sum in the range [6, 8]

NOTE : The answer is guranteed to fit in a 32 bit signed integer.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

Reference: https://www.geeksforgeeks.org/number-of-subarrays-having-sum-in-a-given-range/
-------------------------
	MY NOTES
-------------------------
We will find the number of subarrays whose sum if equal to B-1 and subtract it from the number of subarrays having sum less than or equal to C.
This will give all the subarrays in the range [B, C].
*/
// Time Complexity: O(n), Space complexity: O(1)

int countSubarray(vector<int> &A, int k)
{
    int count = 0;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
 
            // If sum is less than k
            // then update sum and
            // increment count
            if (sum + A[j] <= k) {
                sum = A[j] + sum;
                count++;
            }
            else {
                break;
            }
        }
    }
 
    return count;
}
 
int Solution::numRange(vector<int> &A, int B, int C) {
     return countSubarray(A, C)-countSubarray(A, B-1); 
}
