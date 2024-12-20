# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Time complexity: O(n)
    # In the worst case, the algorithm visits each node exactly once, resulting in a time complexity of O(n).
    # Space complecity: O(log n)
    # The space complexity is determined by the recursion depth of the DFS. Since we are given a 
    # perfect binary tree, the height of the tree is bounded by logn.
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.DFS(root.left, root.right, 0)
        return root

    def DFS(self, left_child, right_child, level):
        if not left_child or not right_child:
            return
        """
        Since we need to reverse the node values at each odd level of the tree 
        that means we should perform the reversal at the parent node level 
        because we will not have access to the left child and right child of 
        the parent in the odd level, we will instead have access to one 
        particular node (it may be the left child or the right child we will 
        have no way to figure that out). Thus, if level%2==0 then it means we 
        are at the parent node and the subsequent left child and the right child 
        in the next level has to be reversed. 
        """
        if level%2==0:
            left_child.val, right_child.val = right_child.val, left_child.val

        self.DFS(left_child.left, right_child.right, level + 1)
        self.DFS(left_child.right, right_child.left, level + 1)
        