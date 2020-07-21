/*
388. Longest Absolute File Path

Level: Medium

https://leetcode.com/problems/longest-absolute-file-path
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
*/

class Solution
{
public:
  int lengthLongestPath(string input)
  {
    stringstream ss(input);
    string line;
    int ans = 0;
    unordered_map<int, int> m;
    while (getline(ss, line, '\n'))
    {
      // last occurrence of '\t' 每个name 前面的 \t 个数不相同，可以拿这个来区分不同level的文件。
      int depth = line.rfind('\t');
      string name = (depth == -1) ? line : line.substr(depth + 1);
      if (name.find('.') != -1) 
        ans = max(ans, m[depth - 1] + (int)name.size());   // name is a file
      else
        m[depth] = m[depth - 1] + name.size() + 1;
    }
    return ans;
  }
};