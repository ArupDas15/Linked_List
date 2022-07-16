/* 
   https://www.interviewbit.com/problems/generate-all-parentheses-ii/
   Solution: https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17

   Generate all Parentheses II
   
   Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

   For example, given n = 3, a solution set is:

	"((()))", "(()())", "(())()", "()(())", "()()()"
	Make sure the returned list of strings are sorted.
	
*/

void solve(int open, int closed, string op, vector<string>& ans){
    if(open==0 && closed==0){
        ans.push_back(op);
        return ;
    }
    if( open!=0){
        string op1 = op;
        // Choose opening brackets
        op1.push_back('(');
        solve(open-1,closed,op1,ans);
    }
    if(open < closed){
        string op2 = op;
        // Chpoose closing brackets.
        op2.push_back(')'); 
        solve(open,closed-1,op2, ans);
        }
}
vector<string> Solution::generateParenthesis(int A) {
    int open = A;
    int closed = A;
    string op = "";
    vector<string> ans;
    solve(open,closed,op,ans);
    return ans; 
}
