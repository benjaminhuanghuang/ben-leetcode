#include <algorithm>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};