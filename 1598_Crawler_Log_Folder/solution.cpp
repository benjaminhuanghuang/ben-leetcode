/*
1598. Crawler Log Folder

Level: Easy

https://leetcode.com/problems/crawler-log-folder
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    int depth = 0;
    for (string op : logs)
    {
      if (op[0] == '.' && op[1] == '.')
      {
        if (depth > 0)
          depth--;
      }
      else if (op[0] == '.')
      {
        continue;
      }
      else
      {
        depth++;
      }
    }
    return depth;
  }
};