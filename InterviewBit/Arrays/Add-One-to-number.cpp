/*
Add One To Number - https://www.interviewbit.com/problems/add-one-to-number/ - Easy
Problem Description

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.


Input Format
First argument is an array of digits.



Output Format
Return the array of digits after adding one.



Example Input
Input 1:

[1, 2, 3]


Example Output
Output 1:

[1, 2, 4]


Example Explanation
Explanation 1:

Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.
*/
// Time complexity: O(n), Space complexity: O(n)
vector<int> Solution::plusOne(vector<int> &A) {
    int i;
    for( i=0;i<A.size();i++){
        if(A[i]==0)
            continue;
        else break;
    }
    vector<int>arr;
    for(int j=i;j<A.size();j++){
        arr.push_back(A[j]);
    }
    int carry = 1, N=arr.size();
    
    vector<int> ans;
    for(int i = N - 1; i >= 0 ; i--){
        ans.push_back((arr[i] + carry) % 10);
        carry = (arr[i] + carry) / 10;
    }
    if(carry)
        ans.push_back(carry);
    // we are doing reverse() because the most significant digit was in the right.
    reverse(ans.begin(),ans.end());
    return ans;
}
    
