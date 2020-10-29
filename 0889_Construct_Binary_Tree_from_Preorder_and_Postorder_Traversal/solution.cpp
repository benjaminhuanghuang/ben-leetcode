/*
889. Construct Binary Tree from Preorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 */
#include <vector>
#include <algorithm>

using namespace std;

#include "common/TreeNode.h"

/*
https://zxi.mytechroad.com/blog/tree/leetcode-889-construct-binary-tree-from-preorder-and-postorder-traversal/

pre = [(root) (left-child) (right-child)]

post = [(left-child) (right-child) (root)]

private int getElementIndex(int[] array, int value) {
  for (int i = 0; i < array.length; i++) {
      if (array[i] == value)
          return i;
  }
  return -1;
}
*/
class Solution
{
public:
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
  {
    return constructFromPrePost(cbegin(pre), cend(pre), cbegin(post), cend(post));
  }

private:
  typedef vector<int>::const_iterator VIT;
  TreeNode *constructFromPrePost(VIT pre_l, VIT pre_r, VIT post_l, VIT post_r)
  {
    if (pre_l == pre_r)
      return nullptr;
    TreeNode *root = new TreeNode(*pre_l);
    ++pre_l;
    --post_r;
    if (pre_l == pre_r)
      return root;
    VIT post_m = next(find(post_l, post_r, *pre_l));
    VIT pre_m = pre_l + (post_m - post_l);
    root->left = constructFromPrePost(pre_l, pre_m, post_l, post_m);
    root->right = constructFromPrePost(pre_m, pre_r, post_m, post_r);
    return root;
  }
};
