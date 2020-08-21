/*
458. Poor Pigs

Level: Hard

https://leetcode.com/problems/poor-pigs
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
  http://bookshadow.com/weblog/2016/11/08/leetcode-poor-pigs/
*/

class Solution
{
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest)
  {
    if (buckets-- == 1)
    {
      return 0;
    }
    int base = minutesToTest / minutesToDie + 1;
    int count = 0;
    while (buckets > 0)
    {
      buckets /= base;
      count++;
    }
    return count;
  }
};