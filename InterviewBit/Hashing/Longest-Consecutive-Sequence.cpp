/*
Longest Consecutive Sequence - EASY - https://www.interviewbit.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 

Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
*/
// Time complexity: O(n), space complexity: O(n)
int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int>s;
    int j;
    for(int i=0;i<A.size();i++){
        s.insert(A[i]);
    }
    int max_len=0,len_cnt;
    for(int i=0;i<A.size();i++){
        if(s.find(A[i]-1)==s.end()){
            //A[i] is the first elements in the consecutive sequence.
            j=A[i];
            while(s.find(j)!=s.end()){
                j++;
            }
            max_len=max(max_len,j-A[i]);
        }
    }
    return max_len;
}