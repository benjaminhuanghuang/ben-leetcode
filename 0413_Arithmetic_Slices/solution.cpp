/*
413. Arithmetic Slices

Level: Medium

https://leetcode.com/problems/arithmetic-slices
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
  int numberOfArithmeticSlices(vector<int> &A)
  {
    int sum = 0;
    int curr = 0;
    for (int i = 2; i < A.size(); ++i)
    {
      if (A[i - 1] - A[i - 2] == A[i] - A[i - 1])
      {
        sum += ++curr;
      }
      else
      {
        curr = 0;
      }
    }
    return sum;
  }
};