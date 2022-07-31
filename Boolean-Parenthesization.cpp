/*
Boolean Parenthesization - Hard - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

Expected Time Complexity: O(N^3)
Expected Auxiliary Space: O(N^2)

Constraints:
1 ≤ N ≤ 200 

Reference: https://www.youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=39

*/

class Solution{
public:
    int solve(string &s, int i, int j, bool isTrue, unordered_map<string, int> &mp){
        // if the string is empty.
        if(i>j)
            return 0;
        // if there is only one operator in the boolean expression.
        if(i==j){
            
            if(isTrue == true)
                return (s[i]=='T')? 1: 0;
            else 
                return (s[i]=='F')? 1: 0;
        }
        string temp = to_string(i);
        temp.append(" ");
        temp.append(to_string(j));
        temp.append(" ");
        temp.append(to_string(isTrue));
        // if the key already exists in the map, return it.
        if(mp.find(temp) != mp.end())
            return mp[temp];
        int lT, lF, rT, rF, ans = 0;
        for(int k = i + 1; k <= j - 1; k+= 2){
            // Compute the temporary answers.
            lT = solve(s, i, k - 1, true, mp)%1003;
            lF = solve(s, i, k - 1, false, mp)%1003;
            rT = solve(s, k + 1, j, true, mp)%1003;
            rF = solve(s, k + 1, j, false, mp)%1003;
            // Combine the temporary answers.
            if(s[k] == '&'){
                if(isTrue == true)
                    ans = (ans + (lT * rT))%1003;
                else
                    ans = (ans + (lF * rF) + (lF * rT) + (lT * rF))%1003;
            }
            else if(s[k] == '|'){
                if(isTrue == true)
                    ans = (ans + (lT * rT) + (lF * rT) + (lT * rF))%1003;
                else
                    ans = (ans + (lF * rF))%1003;
            }
            else if(s[k] == '^'){
                if(isTrue == true)
                    ans = (ans + (lF * rT) + (lT * rF))%1003;
                else
                    ans = (ans + (lT * rT) + (lF * rF))%1003;
            }
        }
        return mp[temp] = ans;
    }
    int countWays(int N, string S){
        unordered_map<string, int> mp;
        // Erase everything from the map.
        mp.clear();
        return solve(S, 0, S.length() - 1, true, mp);
    }
};