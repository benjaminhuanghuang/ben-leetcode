/*
1237. Find Positive Integer Solution for a Given Equation

Level: Easy

https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
class CustomFunction
{
public:
  // Returns f(x, y) for any given positive integers x and y.
  // Note that f(x, y) is increasing with respect to both x and y.
  // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
  int f(int x, int y);
};

class Solution
{
public:
  vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
  {
    vector<vector<int>> ans;
    for (int x = 1; x <= 1000; ++x)
    {
      if (customfunction.f(x, 1) > z)   // test y = 1
        break;
      for (int y = 1; y <= 1000; ++y)
      {
        int t = customfunction.f(x, y);
        if (t > z)
          break;
        if (t == z)
        {
          ans.push_back({x, y});
        }
      }
    }
    return ans;
  }
};