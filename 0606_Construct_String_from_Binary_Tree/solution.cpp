#include <string>
#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  string tree2str(TreeNode *t)
  {
    if (t == nullptr)
      return "";

    const string s = std::to_string(t->val);
    // case 0: s
    if (!t->left && !t->right)
      return s;
    // case 1: s(l)
    if (!t->right)
      return s + "(" + tree2str(t->left) + ")";
    // general: s(l)(r)
    return s + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
  }
};