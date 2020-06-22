/*
371. Sum of Two Integers

Level: Easy

https://leetcode.com/problems/sum-of-two-integers
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
  int getSum(int a, int b)
  {
    while (b != 0)
    {
      // left shift of nagetive value cause error!
      unsigned carry = (unsigned)(a & b) << 1;
      a = a ^ b;
      b = carry;
    }
    return a;
  }
};