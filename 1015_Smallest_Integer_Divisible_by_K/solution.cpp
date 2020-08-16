/*
1015. Smallest Integer Divisible by K

Level: Medium

https://leetcode.com/problems/smallest-integer-divisible-by-k
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
  https://www.youtube.com/watch?v=Df72XNg_bG8
*/

class Solution
{
public:
  int smallestRepunitDivByK(int K)
  {
    if ((K & 1) == 0 || K % 5 == 0)
      return -1;
    int len = 1, num = 1;
    while (num % K != 0)
    {
      num = num * 10 + 1;
      num %= K;
      len++;
    }
    return len;
  }
};