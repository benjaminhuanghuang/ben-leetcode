/*
1104. Path In Zigzag Labelled Binary Tree

Level: Medium

https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  假设用正常顺序构造这样一个 tree， 
  最左边的node会是 1， 2， 4，8， 16，= 2^h  => label的二进制数的最左边的1的位置
  最右边的node是 3，7, 15,  = 2^(h+1) - 1

  lable 离它所在行的最后一个node的距离是 和 prev离prev所在行的第一个node的距离有着联系
*/

class Solution
{
public:
  vector<int> pathInZigZagTree(int label)
  {
    vector<int> ans;
    while (label)
    {
      ans.push_back(label);
      int h = getHeight(label) - 1;
      int prev = ((1 << h) + (1 << (h + 1)) - 1 - label) / 2;
      label = prev;
    }
    return {rbegin(ans), rend(ans)};
  }

private:
  int getHeight(int label)
  {
    int h = 0;
    while (label > 0)
    {
      label = label >> 1;
      h++;
    }
    return h;
  }
};