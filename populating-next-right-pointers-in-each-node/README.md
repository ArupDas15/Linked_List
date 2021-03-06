<h2>116. Populating Next Right Pointers in Each Node</h2><h3>Medium</h3><hr><div><p>You are given a <strong>perfect binary tree</strong>&nbsp;where&nbsp;all leaves are on the same level, and every parent has two children. The binary tree has the following definition:</p>

<pre>struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre>

<p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>

<p>Initially, all next pointers are set to <code>NULL</code>.</p>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="width: 640px; height: 218px;"></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
<strong>Explanation: </strong>Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree is less than <code>4096</code>.</li>
	<li><code>-1000 &lt;= node.val &lt;= 1000</code></li>
</ul></div>
<h2> Solution </h2>
The current solution has Time Complexity: O(n) and Space complexity O(1). 

Another solution that we had learnt was having time complexity: O(n) and Space Complexity: O(n). Video Solution: [here](https://www.youtube.com/watch?v=IPEiWlakbjw).

```
void connect(Node *root)
    {
       // Your Code Here
       queue<Node*>qu;
       qu.push(root);
       while(!qu.empty()){
           int n=qu.size();
           for(int i=0;i<n;i++){
               struct Node* fp=qu.front();
               qu.pop();
               if(i==n-1)
                   fp->nextRight=NULL;
            else fp->nextRight=qu.front();
               if(fp->left)qu.push(fp->left);
               if(fp->right)qu.push(fp->right);
           }
       }
    }
```
