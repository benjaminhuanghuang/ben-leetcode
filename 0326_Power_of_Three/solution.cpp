/*
326. Power of Three

Level: Easy

https://leetcode.com/problems/power-of-three


- 231. Power of Two       # count 1
- 342. Power of Four

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
  bool isPowerOfThree(int n)
  {
    if (n == 1)
      return true;
    else if (n <= 2)
      return false;

    while (n > 3)
    {
      if (n % 3 == 0)
      {
        n /= 3;
      }
      else
      {
        return false;
      }
    }
    return n == 3;
  }

  bool isPowerOfThree_v2(int n)
  {
    if (n < 1)
    {
      return false;
    }

    while (n % 3 == 0)
    {
      n /= 3;
    }
    return n == 1;
  }
};