/*
Colorful Number - EASY - https://www.interviewbit.com/problems/colorful-number/
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
*/

// Solution Approach
// Iterate over all substrings of number, and then check if the number resulting 
// from the multiplication has been stored in the set or not using hashing.
#include<string>
int Solution::colorful(int A) {
    string str = to_string(A);
    int n = str.size(), num,product=1;
    unordered_set<int>s;
    for (int i = 0; i < n; i++)
        //  Print characters from current
        // starting point to current ending
        // point. 
        // Reference: https://www.geeksforgeeks.org/program-print-substrings-given-string/
        // Time Complexity: O(n^3) for subtring generation, Space complexity: O(n) for products
        for (int len = 1; len <= n - i; len++){
            num = stoi(str.substr(i, len));
            product=1;
            while (num != 0){
                product = product * (num % 10);
                num = num / 10;
            }
            if(s.find(product)!=s.end())
                return 0;
            else s.insert(product);
        }
    return 1;
}