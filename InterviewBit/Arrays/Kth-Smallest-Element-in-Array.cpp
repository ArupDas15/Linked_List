/*
Kth Smallest Element in the Array - EASY - https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.

In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based )

NOTE

You are not allowed to modify the array ( The array is read only ). 

Try to do it using constant extra space.

Example:

A : [2 1 4 3 2]
k : 3

answer : 2
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

Solution Approach:
We will find the kth smallest element using binary search approach by reducing the search space and checking in the emtire array if mid is present or not.

*/
// Time Complexity: O(NlogN) - N for traversing the array and logN for binary search.
// Space Complexity: O(1).
int Solution::kthsmallest(const vector<int> &A, int k) {
    if (k > A.size())
        return -1;
    
    int lo = *min_element(A.begin(), A.end());// Time Complexity: O(n)
    int hi = *max_element(A.begin(), A.end());// Time Complexity: O(n)
    
    while (lo <= hi) // Executes log N times. So, time complexity: O(NlogN).
    {
        int mid = lo + (hi - lo)/2;
        int countLess = 0, countEqual = 0;
        
        for (auto i = 0; i<A.size(); ++i)// Time Complexity: O(n)
        {
            if (A[i]<mid)
                ++countLess;
            else if (A[i] == mid)
                ++countEqual;
            if (countLess >= k)
                break;
        }
        
        if (countLess < k && countLess + countEqual >= k)
            return mid;
        else if (countLess >= k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}
