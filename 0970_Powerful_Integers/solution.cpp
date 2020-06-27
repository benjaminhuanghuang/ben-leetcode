/*
970. Powerful Integers

Level: Easy

https://leetcode.com/problems/powerful-integers
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
  https://zxi.mytechroad.com/blog/math/leetcode-970-powerful-integers/
*/

class Solution
{
public:
  vector<int> powerfulIntegers(int x, int y, int bound)
  {
    unordered_set<int> ans;
    for (int a = 1; a < bound; a *= x)
    {
      for (int b = 1; a + b <= bound; b *= y)
      {
        ans.insert(a + b);
        if (y == 1)
          break;
      }
      if (x == 1)
        break;
    }
    return {begin(ans), end(ans)};
  }
};