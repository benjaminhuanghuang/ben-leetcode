/*
492. Construct the Rectangle

Level: Easy

https://leetcode.com/problems/construct-the-rectangle
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
  vector<int> constructRectangle(int area)
  {
    int a = 1, b = 1;
    for (int i = 1; i * i <= area; i++)
    {
      if (area % i == 0)
      {
        a = i;
        b = area / i;
        // break;   DO NOT break,
        // The difference between length L and width W should be as small as possible.
      }
    }
    return {max(a, b), min(a, b)};
  }

  vector<int> constructRectangle_v2(int area)
  {
    int root = (int)sqrt(area);
    while (area % root != 0)
    {
      root--;
    }
    // return W,L, L >= W
    return {area / root, root};
  }
};