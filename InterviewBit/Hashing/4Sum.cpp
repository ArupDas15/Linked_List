/* 
	4 Sum - Medium - https://www.interviewbit.com/problems/4-sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 

Given array S = {1 0 -1 0 -2 2}, and target = 0

A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.

Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. 
Still have a question? Checkout Sample Codes for more details.

*/
// INTERVIEWBIT SOLUTION APPORACH:
/* HINT 1: The naive approach obviously is exploring all combinations of 4 integers using 4 loops.

Now, to look into improving, does it help if we sort the array ?

Also, think of how your approach would change if you did not have to list all of the unique tuples but just tell whether at least one such tuple existed ( YES / NO ).

HINT 2: When the array is sorted, try to fix the least and second least integer by looping over it.
Lets say the least integer in the solution is arr[i] and second least is arr[j].
Now we need to find a pair of integers k and l such that arr[k] + arr[l] is target-arr[i]-arr[j].
To do that, lets try the 2 pointer approach. If we fix the two pointers at the end ( that is, j+1 and end of array ), we look at the sum.
If the sum is smaller than the sum we want, we increase the first pointer to increase the sum.
If the sum is bigger than the sum we want, we decrease the end pointer to reduce the sum.

Note that there is one more solution possible if the question only asked to answer YES / NO to suggest whether there existed at least one tuple with the target sum.
Then we could have gone with an approach using more memory with hashing.

HINT 3: Getting a Time Limit exceeded or Output Limit exceeded ?

Make sure you handle case of empty input []. In C++/C, Usually if you run a loop till array.size() - 2, it can lead to the program running indefinitely as array.size() is unsigned int, and the subtraction just makes it wrap over to a big integer.

Make sure you are not processing the same triplets again. Skip over the duplicates in the array.
Try a input like :
-1 -1 -1 -1 0 0 0 0 1 1 1 1
Ideally, you should get only 3 pairs : {[-1 -1 1 1], [-1 0 0 1], [0 0 0 0]}
 
*/
// INTERVIEWBIT SOLUTION
vector<vector<int> > Solution::fourSum(vector<int> &num, int target) {

        sort(num.begin(), num.end());
        unordered_map<int, set<pair<int, int>>> hash;
        set<vector<int>> ans;
        int n = num.size();
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int a = num[i] + num[j];
                if (hash.count(target - a)) {
                    for (auto &p: hash[target - a]) {
                        vector<int> b = {p.first, p.second, num[i], num[j]};
                        ans.insert(b);
                    }
                }
            }
            for (int j = 0; j < i; j ++) {
                int a = num[j], b = num[i];
                hash[a + b].insert(make_pair(a, b));
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }