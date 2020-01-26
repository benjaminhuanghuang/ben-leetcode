/*
  1028. Recover a Tree From Preorder Traversal [Hard]
  
  https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
*/
#include <string>

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
  TreeNode* recoverFromPreorder(string S) {
    int i = 0;
    return recover(S, i, 0);
  }
private:
  TreeNode* recover(const string& s, int& i, int depth) {    
    const int d = getD(s, i);
    if (d != depth) { i -= d; return nullptr; }    
    auto root = new TreeNode(getVal(s, i));
    root->left = recover(s, i, d + 1);    
    root->right = recover(s, i, d + 1);
    return root;
  }
  
  int getD(const string& s, int& i) {
    int d = 0;
    while (i < s.length() && s[i] == '-') {++d; ++i;}
    return d;
  }
  
  int getVal(const string& s, int& i) {
    int val = 0;
    while (i < s.length() && isdigit(s[i]))
      val = val * 10 + (s[i++] - '0');       
    return val;
  }
};