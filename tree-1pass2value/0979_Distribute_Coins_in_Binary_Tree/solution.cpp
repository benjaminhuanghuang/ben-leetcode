/*
979. Distribute Coins in Binary Tree

https://leetcode.com/problems/distribute-coins-in-binary-tree/
 */

#include "common/TreeNode.h"
#include <algorithm>
using namespace std;

/*
For the subtree rooted at node i, node i has to make the left subtree and right subtree satisfied.
So if left subtree has 3 coins more, it will give node i 3 coins;
If right subtree has 2 coins less, node i will give it 2 coins.
Now the whole subtree is satisfied except for node i.
And we will return back how many coins does node i need so it's parent will give/get the coins and make the whole subtree satisfied.

So for current root, we only cares how many coins does it's left child and right child need since the left subtree and
right subtree are already satisfied. (expect for left child and right child).

Time Complexity: O(N)
Space Complexity: O(1) or O(n) because of recusive stack space
 */
class Solution
{
public:
  int distributeCoins(TreeNode *root)
  {
    int ans = 0;
    balance(root, ans);
    return ans;
  }

private:
  // postorder
  int balance(TreeNode *root, int &ans)
  {
    if (!root)
      return 0;
    int l = balance(root -> left, ans);
    int r = balance(root  ->right, ans);
    ans += abs(l) + abs(r);
    return l + r + root ->val - 1;
  }
};