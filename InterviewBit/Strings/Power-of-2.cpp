/*
Power of 2 - Medium - https://www.interviewbit.com/problems/power-of-2/
Find if Given number is power of 2 or not. 

More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
*/
/*		SOLUTION APPROACH
There is no shortcut to this problem. We need to divide the number by 2 till it is greater than 1. At any point, if the last digit is odd, then the number is not a power of 2.
The division process is just the simulation of human division process.
Start from the first digit. If the current digit is less than 2, then we append the next digit to current digit, and append 0 to our answer.

NOTE: In this question, it is given that the number length can be more than 64, however if the number was an integer then we could have hecked if (n&(n-1))==0. 
If it is 0 then the number is power of 2. E.g. 4&3==0 so 4 is a power of 2. The solution for such type of question is given here: 
https://github.com/ArupDas15/Linked_List/tree/master/231-power-of-two 
Time complexity with integer as input would be O(1) and space complexity would be O(1).
*/

// Time complexity: O(n), space complexity: O(1)
bool checkeven(char x){
    if((int(x)-48)%2==0)
        return true;
    return false;
}
int Solution::power(string A) {
    if(!checkeven(A[A.size()-1]))
        return 0;
    int sum=0,num,c=0;
    // At any point, if the last digit is odd, then the number is not a power of 2.
    while(checkeven(A[A.size()-1])){
        for(int i = 0;i<A.size();i++){
                num = c*10+(A[i]-'0');
                A[i]=(num/2)+'0'; // storing the quotient after diving num by 2.
                c=num%2; //storing the remainder after diving num by 2. 
        }
    }
    for(int i=0;i<A.size();i++){
        sum = sum + (int(A[i]) - 48);   
    }
    if(sum==1)// you are checking if the quotient after all the repeated divisions by 2 is 1.
        return 1;
    else return 0;
}
