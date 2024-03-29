/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Reference: https://www.youtube.com/watch?v=ZbybYvcVLks
// Leetcode discussion: https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/1803302/C%2B%2Bor-Detailed-Explanation-w-WHY-oror-Covering-Integer-overflow-conditionor-DRY-RUN
#include<bits/stdc++.h>
class Solution {
public:
     int widthOfBinaryTree(TreeNode* root) {
       if (!root)
           return 0;
       int ans = 0;
       queue < pair < TreeNode * , unsigned int >> q;
       q.push({root,0});
       while (!q.empty()) {
            int size = q.size();
            unsigned int curMin = q.front().second;
            unsigned int leftMost, rightMost;
            for (int i = 0; i < size; i++) {
                unsigned int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
                TreeNode * temp = q.front().first;
                q.pop();
                if (i == 0) leftMost = cur_id;
                if (i == size - 1) rightMost = cur_id;
                if (temp -> left)
                    q.push({ temp -> left, cur_id * 2 + 1 });
                if (temp -> right)
                    q.push({temp -> right, cur_id * 2 + 2});
            }
            if(ans< rightMost - leftMost + 1)
                ans = rightMost - leftMost + 1;
            }
            return ans;
     }
};
