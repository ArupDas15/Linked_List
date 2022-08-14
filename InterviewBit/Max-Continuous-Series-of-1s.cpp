/*
Max Continuous Series of 1s - Medium - https://www.interviewbit.com/problems/max-continuous-series-of-1s/

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.

Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

------------------------------
		MY NOTES
------------------------------
Based on variable size sliding window technique.
Maintain the number of 0s in the current range. The range becomes invalid when count of 0s exceeds B.
*/

// Time complexity: O(n), space complexity: O(1)

vector<int> Solution::maxone(vector<int> &A, int B) {
    int start_idx = 0, j = 0;
    int cnt=0;
    int range=0,start=0;
    while(j<A.size()){
        if(A[j]==0)
            cnt++;
        if(cnt>B){
            while(A[start]!=0){
            start++;
            }
            start++;
            cnt--;
        }
        if(range<j-start+1){
            range=j-start+1;
            start_idx=start;
        }
        j++;
    }
    vector<int>result;
    for(int i=start_idx; i<start_idx+range;i++){
        result.push_back(i);
    }
 
    // Return the sliced vector
    return result;
}
