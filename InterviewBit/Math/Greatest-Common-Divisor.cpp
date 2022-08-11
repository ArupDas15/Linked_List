/*
Greatest Common Divisor - Medium - https://www.interviewbit.com/problems/greatest-common-divisor/

Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.

Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 
NOTE : DO NOT USE LIBRARY FUNCTIONS

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
*/
// Time Complexity: O(log(min(a, b))
// Reference: https://www.geeksforgeeks.org/time-complexity-of-euclidean-algorithm/

int Solution::gcd(int a, int b) {
    if(b ==0) return a;
    if(a%b==0)
        return b;
    if (a>b)
        return gcd(a%b,b);
    else return gcd(b%a,a);
}
