/*
779. K-th Symbol in Grammar

Level: Medium

https://leetcode.com/problems/k-th-symbol-in-grammar
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
  https://www.cnblogs.com/grandyang/p/9027098.html
*/

class Solution
{
public:
  int kthGrammar(int N, int K)
  {
    if (N == 1)
      return 0;
    if (K % 2 == 0)
      return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
    else
      return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
  }
};