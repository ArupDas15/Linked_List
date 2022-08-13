/*
Allocate Books - Medium - https://www.interviewbit.com/problems/allocate-books/
Given an array of integers A of size N and an integer B.

College library has N bags,the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return that minimum possible number
Constraints

1 <= N <= 10^5
1 <= A[i] <= 10^5
For Example

Input 1:
    A = [12, 34, 67, 90]
    B = 2
Output 1:
    113
Explanation 1:
    There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

        Of the 3 cases, Option 3 has the minimum pages = 113.

Input 2:
    A = [5, 17, 100, 11]
    B = 4
Output 2:
    100
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

Reference: https://www.youtube.com/watch?v=gYmWHvRHu-s
*/
// Time Complexity: O(N * log(sumOfArrElements - max_element_in_arr))

#include<numeric> // We are using this library for accumulate().
bool isAllocationPossible(vector<int> &A, int B, int V){
    int sum = 0;
    int cnt_of_student = 1;
    for(auto b: A){
        if(sum+b>V){
            cnt_of_student++;
            sum=b;
            if (cnt_of_student > B) 
                return false;
        }
        else sum=sum+b;
    }
    return true;  
}
int Solution::books(vector<int> &A, int B) {
    int N = A.size();
    if(B > N)
        return -1;
    if(B==N)
        return *max_element(A.begin(),A.end());
    int low = *max_element(A.begin(),A.end());
    int high = std::accumulate(A.begin(),A.end(),0);
    int mid;
    int ans;
    while(low<=high){
        mid  = low + ((high-low)/2);
        if(isAllocationPossible(A,B,mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
