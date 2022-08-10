/*
Wave Array - EASY - INTERVIEWBIT

Given an array of integers,  sort the array into a wave like array and return it, 

In other words, arrange the elements into a sequence such that  a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 

So, in example case, you will return [2, 1, 4, 3]

*/
// Approach: Sort the array first. Now you can get the wave pattern by taversing the elements in the array only once.
// if the current element is at an even index and is lesser than the next element then perform a swap.
// if the current element is at an odd index and is greater than the next element then perform a swap. 
// To understand this approach you use a pen and paper and take an example, say, A = [4, 6, 8, 11, 15, 17].
// At i = 0(even index): 4 < 6. so swap. After swap, A = [6, 4, 8, 11, 15, 17].
// At i = 1(odd index): 4 < 8. Condition of wave is not violated so no need to swap. (You can draw a wave and check this)
// At i = 2(even index): 8 < 11. So swap. After swap, A = [6, 4, 11, 8, 15, 17].
// At i =3(odd index): 8 < 15. Condition of wave is not violated so no need to swap.
// At i=4(even index): 15<17. Condition of wave is violated so we need to swap. After swap, A = [6, 4, 11, 8, 17, 15].

// Time Complexity: Time for sorting the array +  time for traversing the sorted array = O(nlogn) + o(n) = O(nlogn).

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size()-1;i++){
        if(i%2==0){
            // check if A[i]<A[i+1]
            if(A[i]<A[i+1])
                swap(A[i],A[i+1]);
        }
        else {
            // check if A[i]>A[i+1]
            if(A[i]>A[i+1])
                swap(A[i],A[i+1]);
        }
    }
    return A;
}
