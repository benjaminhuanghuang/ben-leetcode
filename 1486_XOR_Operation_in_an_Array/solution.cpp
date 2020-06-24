/*
1486. XOR Operation in an Array

Level: Easy

https://leetcode.com/problems/xor-operation-in-an-array
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  int xorOperation(int n, int start)
  {
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      ans ^= start + 2 * i;
    }
    return ans;
  }
};