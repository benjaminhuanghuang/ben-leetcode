/*
1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

Level: Medium

https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-1414-find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
  Find the largest fibonacci numbers x that x <= k, ans = 1 + find(k – x)
*/

class Solution
{
public:
  int findMinFibonacciNumbers(int k)
  {
    if (k == 0)
      return 0;
    int f1 = 1;
    int f2 = 1;
    while (f2 <= k)
    {
      swap(f1, f2);
      f2 += f1;
    }
    return 1 + findMinFibonacciNumbers(k - f1);
  }
};