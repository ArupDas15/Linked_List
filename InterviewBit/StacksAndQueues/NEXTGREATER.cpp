/*
NEXTGREATER - EASY - https://www.interviewbit.com/problems/nextgreater/
Given an array, find the next greater element G[i] for every element A[i] in the array.  The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is minimum possible AND 
    j > i AND
    A[j] > A[i]
Elements for which no greater element exist, consider next greater element as -1.

Example:

Input : A : [4, 5, 2, 10]

Output : [5, 10, 10, -1]

Example 2:

Input : A : [3, 2, 1]

Output : [-1, -1, -1]

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

*/
// Below code is not optimised. The time complexity of below code is O(n^2) and space complexity is O(1). However, this solution got accepted in InterviewBit.

/*
vector<int> Solution::nextGreater(vector<int> &A) {
    int n =A.size();
    vector<int>ans;
    if(n==1){
        ans.push_back(-1);
        return ans;
    }
    int found;
    for(int i = 0; i < n; i++){
        found  = 0;
        for(int j=i+1; j < n; j++)
            if(A[j]>A[i]){
                found = 1;
                ans.push_back(A[j]);
                break;
            }
        if(found == 0)
            ans.push_back(-1);
    }
    return ans;
}
*/
// -----------OPTIMIsED CODE--------------------------
// Time complexity: O(n), space complexity: O(n)
// Reference: https://www.geeksforgeeks.org/next-greater-element/
vector<int> Solution::nextGreater(vector<int> &A) {
    int i=0, n=A.size();
    stack<int>s;
    vector<int>ans(n,0);
    if(n==1){
        ans[0]=-1;
        return ans;
    }
     for (int i = n - 1; i >= 0; i--) {
   /* We iterate backwards instead from front because in some cases the output elements would not be produced in the same order as the input. E.g. A : [11, 13, 21, 3].
    if stack is not empty, then
        pop elements from stack until stack top > A[i]
        (i.e. keep popping until element in stack is greater than current array element under consideration).
        If the stack gets empty in this process then no elements was found to be nextgreater than A[i].
    */
        if (!s.empty()) {
            while (!s.empty() && s.top() <= A[i]) {
                s.pop();
            }
        }
        if(s.empty())
            ans[i] = -1;
        else ans[i]= s.top();
        s.push(A[i]);
    }
    return ans;
}
