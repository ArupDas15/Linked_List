/*
Painter's Partition Problem - Medium - https://www.interviewbit.com/problems/painters-partition-problem/

Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a configuration where painter 1 paints board 1 and 3 but not 2 is invalid.
Return the ans % 10000003

Input Format

The first argument given is the integer A.
The second argument given is the integer B.
The third argument given is the integer array C.
Output Format

Return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board % 10000003.
Constraints

1 <=A <= 1000
1 <= B <= 10^6
1 <= C.size() <= 10^5
1 <= C[i] <= 10^6
For Example

Input 1:
    A = 2
    B = 5
    C = [1, 10]
Output 1:
    50
Explanation 1:
    Possibility 1:- same painter paints both blocks, time taken = 55units
    Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
    There are no other distinct ways to paint boards.
    ans = 50%10000003

Input 2:
    A = 10
    B = 1
    C = [1, 8, 11, 3]
Output 2:
    11
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

*/
// Approach same as allocate books because the contraints in the both the questions is similar.
// A board has to be painted by only one painter.
// The boards should be allocated in contiguous manner to the painter.
// Every board will be allocated to a painter.
// Hence we keep assigning boards to painter greedily till the time taken < mid. If you run out of painters, isPossible = false, else isPossible = true.
// Time Complexity: O(N*log(max_element_in_C-sumOfElementsinC))

bool isPossible(int A, int B, vector<int>&C, int time_taken){
    int cnt= 1;
    int sum = 0; // sum stores the time taken by a painter.
    for(int i = 0; i<C.size();i++){
        if((sum+C[i])% 10000003>time_taken){
            sum = C[i]% 10000003; // Reset sum to C[i] when time taken by previous painter exceeds mid.
            cnt++; // Increase the number of painters required by 1.
            if(cnt>A)
                return false;
        }
        else sum = (sum + C[i])% 10000003;
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int sum = 0;
    for(int i=0;i<C.size();i++){
        sum = (sum + (C[i]% 10000003))% 10000003;
    }
    if(A==1)
        return (B*sum)% 10000003;
    if(A>C.size())
        return (B*(*max_element(C.begin(),C.end())% 10000003))% 10000003;
    long long int low = *max_element(C.begin(),C.end());
    long long int high = sum;
    long long int mid;
    int ans;
    while(low<=high){
        mid = (low + (high-low)/2)% 10000003;
        if(isPossible(A,B,C, mid)){
            ans = (B*mid)% 10000003;
            high = mid-1;
        }
        else low = mid+1;    
    }
    return ans;
}
