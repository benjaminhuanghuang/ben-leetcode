/*
258. Add Digits

Level: Easy

https://leetcode.com/problems/add-digits
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
  int addDigits(int num)
  {
    int next = getNext(num);
    while (next >= 10)
    {
      next = getNext(next);
    }
    return next;
  }

  int getNext(int num)
  {
    int sum = 0;
    while (num / 10 > 0)
    {
      sum += num % 10;
      num = num / 10;
    }
    sum += num;
    return sum;
  }
};