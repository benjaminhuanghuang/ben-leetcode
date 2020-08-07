/*
1111. Maximum Nesting Depth of Two Valid Parentheses Strings

Level: Medium

https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
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
  https://www.youtube.com/watch?v=q_53SO8Bz_o
*/

class Solution
{
public:
  vector<int> maxDepthAfterSplit(string seq)
  { // Get the max depth
    int depth = 0, maxDepth = 0;
    for (char c : seq)
    {
      depth += c == '(' ? 1 : -1;
      maxDepth = max(maxDepth, depth);
    }

    vector<int> res(seq.size(), 0);

    // maxCount / 2 is the threshold for being in A or B. A if count < threshold.
    int threshold = maxDepth / 2;
    depth = 0;

    for (int i = 0; i < seq.size(); ++i)
    {
      char c = seq[i];
      depth += c == '(' ? 1 : -1;
      if ((c == '(' && depth > threshold) || (c == ')' && depth >= threshold))
      {
        res[i] = 1;
      }
    }

    return res;
  }
};