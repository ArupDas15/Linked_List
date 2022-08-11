/*
Rearrange Array - Medium - https://www.interviewbit.com/problems/rearrange-array/
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
Lets say N = size of the array. Then, following holds true :

All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

Solution Approach:
If you had extra space to do it, the problem will be very easy.
Store a copy of Arr in B.

And then for every element, do Arr[i] = B[B[i]]

Lets restate what we just said for extra space :

If we could somehow store 2 numbers in every index ( that is, Arr[i] can contain the old value and the new value somehow ), then the problem becomes very easy.
NewValue of Arr[i] = OldValue of Arr[OldValue of Arr[i]]

Now, we will do a slight trick to encode 2 numbers in one index.
This trick assumes that N * N does not overflow.

1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
2) Divide every element by N.
Given a number as

   A = B + C * N   if ( B, C < N )
   A % N = B
   A / N = C
We use this fact to encode 2 numbers into each element of Arr.

*/

void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<A.size();i++){
        // We are going to store old and new value together in every cell.
        // We will use the remainder theorem: A = Quotient + remainder
        //A = B + C where B = A / n and C = A % n.
        // So we will store B + C in every cell where B is the new number and C is the old number.
        // Later we will remove C from the Array A by dividing every element in A by n. 
        A[i]=(A[A[i]]%n)*n + A[i];
    }
    
    for(int i=0;i<A.size();i++){
        A[i]=A[i]/n;
    }
}
