/*
331. Verify Preorder Serialization of a Binary Tree

Level: Medium

https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <sstream>
#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  If a node is not null, it must has two children, thus verify left subtree and right subtree recursively.
  If a not is null, the current char must be ‘#’

*/

class Solution
{
public:
  bool isValidSerialization(string preorder)
  {
    int pos = 0;
    return isValid(preorder, pos) && pos == preorder.length();
  }

private:
  bool isValid(const string &s, int &pos)
  {
    if (pos >= s.length())
      return false;
    if (isdigit(s[pos]))
    {
      while (isdigit(s[pos]))
        ++pos;
      return isValid(s, ++pos) && isValid(s, ++pos);
    }
    return s[pos++] == '#';
  }
};

/*
 // 不断的砍掉叶子节点。最后看看能不能全部砍掉。
    // ”9,3,4,#,#,1,#,#,2,#,6,#,#” 遇到x # #的时候，就把它变为 #
 
*/
class Solution
{
public:
  bool isValidSerialization(string preorder)
  {
    vector<string> s;
    string word;
    stringstream ss(preorder);
    while (getline(ss, word, ','))
    {
      s.push_back(word);

      while (s.size() >= 3 && s.back() == "#" && s[s.size() - 2] == "#" && s[s.size() - 3]!="#")
      {

        s.pop_back();
        s.pop_back();
        s.pop_back();

        s.push_back("#");
      }
    }

    return (s.size() == 1 && s.back()== "#");
  }
};