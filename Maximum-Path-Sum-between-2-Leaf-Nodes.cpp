/*
 Maximum Path Sum between 2 Leaf Nodes - HARD - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.


Example 1:

Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation:
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.
Example 2:

Input:    
            -15                               
         /      \                          
        5         6                      
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  
Output:  27
Explanation:
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

Your Task:  
You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)


Constraints:
2  ≤  Number of nodes  ≤  10^4
-10^3  ≤ Value of each node ≤ 10^3

Reference: https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
*/
class Solution {
public:
    int solve(Node* root, int &res){
        // Base Case: When the root is empty.
        if(root == nullptr)
            return 0;
        // Hypothesis
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        // Induction
        int temp_ans;
        if (root->left && root->right) {
            res = max(res, left + right + root->data);
            temp_ans = root->data + max(left, right);
        }
        else if (root->left)
            temp_ans = root->data + left;
        else if (root->right)
            temp_ans = root->data + right;
        else
            temp_ans = root->data;
        return temp_ans;
    }
    int maxPathSum(Node* root)
    {
        int res = INT_MIN;
        int ans = solve(root, res);
        if(root->left && root->right)
            return res;
        return max(res, ans);
    }
};