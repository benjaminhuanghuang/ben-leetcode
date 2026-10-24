/*
202. Happy Number

Level: Easy

https://leetcode.com/problems/happy-number
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
  bool isHappy(int n)
  {
    if (n < 1)
    {
      return false;
    }

    unordered_set<int> set;

    int tmp;
    int newN;

    // n不为1，并且n的值不能重复出现，否则会死循环
    while (n != 1 && !set.count(n))
    {
      set.insert(n);
      newN = 0;
      while (n > 0)
      {
        tmp = n % 10;
        n /= 10;
        newN += tmp * tmp;
      }

      n = newN;
    }

    return n == 1;
  }
};