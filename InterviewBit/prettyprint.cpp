/*
PRETTYPRINT - EASY - https://www.interviewbit.com/problems/prettyprint/

Print concentric rectangular pattern in a 2d matrix. 

Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.

Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.

Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

*/

vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int>>ans(2*A-1,vector<int>(2*A-1));
    int n = 2*A-1;
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                ans[i][j]=A;
                ans[n-i-1][j]=A;
            }
            else{
                if(j >= i && j<= n - i - 1)
                {
                    ans[i][j] = ans[i - 1][j] - 1;
                    ans[n - i - 1][j] = ans[i][j];
                }
                else
                {
                    ans[i][j] = ans[i - 1][j];
                    ans[n - i - 1][j] = ans[i][j];
                }
            }
        }
    }
    return ans;
}
