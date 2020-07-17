/*
223. Rectangle Area

Level: Medium

https://leetcode.com/problems/rectangle-area
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
*/

class Solution
{
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
  {
    long sum = (long)(C - A) * (D - B) + (H - F) * (G - E);
    if (E >= C || F >= D || B >= H || A >= G)
      return sum;
    return sum - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F)));
  }
};