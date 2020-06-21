/*
1009. Complement of Base 10 Integer

Level: Easy

https://leetcode.com/problems/complement-of-base-10-integer
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
  int bitwiseComplement(int N)
  {
    if (N == 0)
      return 1;

    int ans = 0;
    bool find1 = false;
    for (int i = 31; i >= 0; i--)
    {
      int mask = 1 << i;
      if ((N & mask) && !find1)
      {
        find1 = N & mask;
      }
      if ((N & mask) == 0 && find1)
      {
        ans += mask;
      }
    }
    return ans;
  }
};