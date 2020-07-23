/*
481. Magical String

Level: Medium

https://leetcode.com/problems/magical-string
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
*/

class Solution
{
public:
  int magicalString(int n)
  {
    if (n <= 0)
      return 0;
    if (n <= 3)
      return 1;

    int a[n + 1];
    a[0] = 1;
    a[1] = 2;
    a[2] = 2;
    int head = 2, tail = 3, num = 1, result = 1;

    while (tail < n)
    {
      for (int i = 0; i < a[head]; i++)
      {
        a[tail] = num;
        if (num == 1 && tail < n)
          result++;
        tail++;
      }
      num = num ^ 3;
      head++;
    }

    return result;
  }
};