/*
Scramble String - InterviewBit - Hard - https://www.interviewbit.com/problems/scramble-string/

Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0
*/
// Solution using Recursion.
// Reference: https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40
/*
int Solution::isScramble(const string A, const string B) {
    if(A.length() != B.length())
        return false;
    if(A == "" && B == "")
        return true;
    if(A.compare(B) == 0)
        return true;
    if(A.length() <= 1)
        return false;
    int n = A.length();
    int case1, case2;
    bool flag = false;
    for(int i = 1; i <= n-1; i++){
        case1 = (isScramble(A.substr(0,i), B.substr(n - i, i)) && isScramble(A.substr(i, n - i), B.substr(0, n-i)));
        case2 = (isScramble(A.substr(0,i), B.substr(0, i)) && isScramble(A.substr(i, n - i), B.substr(i, n - i)));
        if(case1 || case2){
            flag = true;
            break;
        }
    }
    return flag;
}

*/
// Memoised Solution.
// Reference: https://www.youtube.com/watch?v=VyHEglhbm-A&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=41
bool solve(const string A, const string B, unordered_map<string, bool> &mp){
    if(A.compare(B) == 0)
        return true;
    if(A.length() <= 1)
        return false;
    int n = A.length();
    int case1, case2;
    bool flag = false;
    
    string key = A;
    key.push_back(' ');
    key.append(B);
    if(mp.find(key) != mp.end())
        return mp[key];
        
    for(int i = 1; i <= n-1; i++){
        case1 = (solve(A.substr(0,i), B.substr(n - i, i), mp) && solve(A.substr(i, n - i), B.substr(0, n-i), mp));
        case2 = (solve(A.substr(0,i), B.substr(0, i), mp) && solve(A.substr(i, n - i), B.substr(i, n - i), mp));
        if(case1 || case2){
            flag = true;
            break;
        }
    }
    
    return mp[key] = flag;
}
int Solution::isScramble(const string A, const string B) {
    if(A.length() != B.length())
        return false;
    if(A == "" && B == "")
        return true;
    unordered_map<string, bool> mp;
    mp.clear();
    return solve(A, B, mp);
}
