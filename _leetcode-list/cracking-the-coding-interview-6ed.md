# Cracking the Coding Interview 


Github: https://github.com/careercup

## Arrays and Strings


## Linked list


## Tree and Graphs

### 1.  Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.

  BFS, visited

### 2. Sorted array to Binary search tree

Leetcode 108. Convert Sorted Array to Binary Search Tree

https://zxi.mytechroad.com/blog/tree/leetcode-108-convert-sorted-array-to-binary-search-tree/

Time complexity: O(N)

Space complexity: O(logN)

### 3. List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

Leetcode 


Solution 1: pre-order traversal algorithm

Solution 2: breadth-first search


### 4. Check Balanced
Solution 1: Recursion,  O(N log N) since each node "touched" once per node above it.
Solution 2: O(N) O(H)


### 5. Validate BST
Solution 1: Recursion, inorder traversal, compare last one with current one

Solution 2: Recursion, checkBST(TreeNode n, int min, int max)
  Time complexity: O(N)
  Space complexity: O(logN)


### 6. Successor: Write an algorithm to find the "next" node
* You may assume that each node has a link to its parent.

中序遍历，会遍历左子树，然后是当前节点，接着是右子树
对一个假想的节点，下一个节点应该位于右子树。应该是右子树最左边的节点。
若这个节点没有右子树，必须回到n的父节点，记作q
n在q的左边，那么，下一个节点就是q（中序遍历，left -> current ->right）。
若n在q的右边，则表示已遍历q的子树。我们需要从q的parent node。

### 7. Build Order:
topological sort:
Leetcode 210. Course Schedule II    
Use BFS, queue and indegree



### 8 首个共同祖先  设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。不得将其他的节点存储在另外的数据结构中。注意：这不一定是二叉搜索树。