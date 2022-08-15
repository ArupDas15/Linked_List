/*
Redundant Braces - EASY - https://www.interviewbit.com/problems/redundant-braces/

Problem Description
 
 

Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.

Problem Constraints
1 <= |A| <= 105

Input Format
The only argument given is string A.

Output Format
Return 1 if A has redundant braces, else return 0.

Example Input
Input 1:
 A = "((a+b))"

Input 2:
 A = "(a+(a+b))"

Example Output
Output 1:
 1

Output 2:
 0

Example Explanation
Explanation 1:
 ((a+b)) has redundant braces so answer will be 1.
Explanation 2:

 (a+(a+b)) doesn't have have any redundant braces so answer will be 0.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

*/
/* Solution Approach:
We push only the opening brace into the stack. There are two cases we check:
1. if the part of the input contains redundant brace of the form (a). Eg. (a*b+(a)).
2. If the number of braces in the input is greater than number of operands, then the input is redundant.
Notice that in this question number of opening braces is equal to the number of closing braces. You can confirm this from the interviewer when such a question is given.
Time complexity: O(n), space complexity:O(n) if the input contains only braces in the worst case.
*/
int Solution::braces(string A) {
    stack<char>st;
    int countop=0;
    int countb =0;
   
    for(int i=0;i<A.size();i++){
        if(A[i]=='(')
            st.push(A[i]);
        
        else if(A[i]==')'){
            st.pop();
            countb++;
        }
        else if(A[i] == '+' || A[i] == '-' || A[i] == '/' || A[i] == '*')   countop++;
        // You need below constraint for inputs like: A : "(a*b+(a))". For this input
        // the number of pairs of braces(i.e. ()) and operands(*,+) are matching so if
        // you dont have this case then it will not be able to detect the presence of 
        // redundant braces.
        if(i-1>=0 && i+1<A.size() && A[i-1]=='(' && A[i+1]==')')
            return 1;  
    }
    if (countb>countop)
        return 1;
    return 0;
}
