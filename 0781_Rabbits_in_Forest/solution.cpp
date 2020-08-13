/*
781. Rabbits in Forest

Level: Medium

https://leetcode.com/problems/rabbits-in-forest
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
  https://zxi.mytechroad.com/blog/math/leetcode-781-rabbits-in-forest/
  
  Solution: Math
    Say there n rabbits answered x.
    if n <= x: they can have the same color
    if n > x: they must be divided into groups, each group has x + 1 rabbits, and there are at least ceil(n / (x+1)) groups.
    So there will be ceil(n / (x + 1)) * (x + 1) rabbits. This expression can be expressed as (n + x) / (x + 1) * (x + 1) in programming languages. (n + x) // (x + 1) * (x + 1) for Python3.
*/

class Solution
{
public:
  int numRabbits(vector<int> &answers)
  {
    vector<int> counts(*max_element(begin(answers), end(answers)) + 1);
    for (const int answer : answers)
      ++counts[answer];
    int total = 0;
    for (int x = 0; x < counts.size(); ++x)
      total += (counts[x] + x) / (x + 1) * (x + 1);
    return total;
  }
};