# Tree
## Tutorial
- [花花酱 LeetCode Binary Trees 二叉树 - 刷题找工作 SP12](https://www.youtube.com/watch?v=PbGl8_-bZxI)


## Inorder Traversal 
- Inorder Traversal using Recursion
```
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {    
    vector<int> ans;
    inorderTraversal(root, ans);
    return ans;
  }
private:
  void inorderTraversal(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);     // visit curr inorder
    inorderTraversal(root->right, ans);    
  }
};
```
- Inorder Traversal Iterative using stack
https://www.youtube.com/watch?v=VsxLHGUqAKs

1. Create stack
2. Init current node as root.
3. Push current node to stack and set current = current-> left until current is null
4. if current is null and stack is not empty then
  a. Pop the top item from stack
  b. Print the poped item, set current = popped item-> right.
  c. Gto to step 3
5. If current is null and stack is empty then we are done

```
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> ans;
    stack<TreeNode*> s;
    TreeNode* curr = root;   // start with current node
    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }
      curr = s.top(); s.pop();
      ans.push_back(curr->val); // visit curr
      curr = curr->right;
    }    
    return ans;
  }
};
``` 
- Morris Inorder Traversal
https://www.youtube.com/watch?v=wGXB9OWhPTg

We find the "inorder pedecessor" of a node before goint on the left subtree

```
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;   // start with current node
    while(curr)
    {
      // if left is null, visit curr node and go to right 
      if(curr->left == nullprt) 
      {
        ans.push_back(curr->val);  // visit curr
        curr = curr->right;
      }
      else
      {
        // find the predecessor of current node
        TreeNode* predecessor = curr->left;
        while(predecessor->right != curr && predecessor->right !=null){
          predecessor = predecessor->right;
        }

        if(predecessor->right == null){
          predecessor->right = current;   // connect predecessor and current
          current = current->left;
        }
        else {   // left is already visited. got right
          predecessor->right = null;
          ans.push_back(curr->val);  // visit curr
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};
``` 

## Preorder Traversal 
- Recursion
```
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;  

    function<void(TreeNode*)> preorder = [&](TreeNode* n) {
      if (!n) return;
      ans.push_back(n->val);
      preorder(n->left);
      preorder(n->right);
    };

    preorder(root);
    return ans;
  }
};
```

- Stack
```
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> s;
    if (root) s.push(root);

    while (!s.empty()) {
      TreeNode* n = s.top();
      ans.push_back(n->val);
      s.pop();
      // push right before lest
      if (n->right) s.push(n->right);
      if (n->left) s.push(n->left);            
    }
    return ans;
  }
```

- Morris Inorder Traversal
https://www.youtube.com/watch?v=wGXB9OWhPTg
```
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;   // start with current node
    while(curr)
    {
      // if left is null, visit curr node and go to right 
      if(curr->left == nullprt) 
      {
        ans.push_back(curr->val);  // visit curr
        curr = curr->right;
      }
      else
      {
        // find the predecessor
        TreeNode* predecessor = curr->left;
        while(predecessor->right != curr && predecessor->right !=null){
          predecessor = predecessor->right;
        }
        if(predecessor->right == null){
          predecessor->right = current;
          current = current->left;
        }
        else {   // left is already visited. got right
          predecessor->right = null;
          curr = curr->right;
        }
      } 
    }
    return ans;
  }
};
```
## Postorder Traversal 

https://zxi.mytechroad.com/blog/tree/leetcode-145-binary-tree-postorder-traversal/

- Recursion
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;        
        postorderTraversal(root, ans);
        return ans;
    }
    
    void postorderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        postorderTraversal(root->left, ans);
        postorderTraversal(root->right, ans);
        ans.push_back(root->val);
    }
};
```
- Stack
reversed poseorder:
  root
  rev_poseorder(root->right)
  rev_poseorder(root->left)
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        deque<int> ans;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* n = s.top();
            s.pop();
            ans.push_front(n->val); // O(1)
            if (n->left) s.push(n->left);
            if (n->right) s.push(n->right);
        }   
        return vector<int>(ans.begin(), ans.end());
    }
};
```


## Layer / Row access
```
  while (q.size())
  {
    int size = q.size();
    while (size--)
    {
      
    }
  }
```

## Probelems
- 124. Binary Tree Maximum Path Sum
- 199. Binary Tree Right Side View        # BFS, DFS
- 863. All Nodes Distance K in Binary Tree
- 1080. Insufficient Nodes in Root to Leaf Paths     
- 1028. Recover a Tree From Preorder Traversal                # value and depth   
- 1110. Delete Nodes And Return Forest                        # set
- 1261. Find Elements in a Contaminated Binary Tree
- 1339. Maximum Product of Splitted Binary Tree               # Sum
- 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
- 1315. Sum of Nodes with Even-Valued Grandparent
- 1325. Delete Leaves With a Given Value                    # delete leaf nodes
- 1367. Linked List in Binary Tree                 #  recursion
- 1448. Count Good Nodes in Binary Tree
- 1457. Pseudo-Palindromic Paths in a Binary Tree

## Validation
- 331. Verify Preorder Serialization of a Binary Tree      # stack

## Traversal( Recusive & iterative)
- 102. Binary Tree Level Order Traversal
- 103. Binary Tree Zigzag Level Order Traversal
- 144. Binary Tree Preorder Traversal
- 145. Binary Tree Postorder Traversal                    # iterative & Recusive, Huahua 
- 173. Binary Search Tree Iterator 
- 590. N-ary Tree Postorder Traversal    
- 589. N-ary Tree Preorder Traversal    
- 987. Vertical Order Traversal of a Binary Tree                # 
- 1302. Deepest Leaves Sum

## Serialize & Deserialize
- 297. Serialize and Deserialize Binary Tree
- 449. Serialize and Deserialize BST

## Build tree
- 889. Construct Binary Tree from Preorder and Postorder Traversal

## Transform
- 114. Flatten Binary Tree to Linked List

## Go through
- 530. Minimum Absolute Difference in BST
- 671. Second Minimum Node In a Binary Tree
- 783. Minimum Distance Between BST Nodes

## Layer / Row access
- 513. Find Bottom Left Tree Value
- 515. Find Largest Value in Each Tree Row
- 1161. Maximum Level Sum of a Binary Tree

## Compare
- 951. Flip Equivalent Binary Trees