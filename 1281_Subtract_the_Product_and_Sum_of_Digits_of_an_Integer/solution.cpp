/*
1281. Subtract the Product and Sum of Digits of an Integer

Level: Easy

https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
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

class Solution
{
public:
  int subtractProductAndSum(int n)
  {
    int product = 1;
    int sum = 0;
    while (n > 0)
    {
      int digit = n % 10;
      product *= digit;
      sum += digit;
      n = n / 10;
    }
    return product - sum;
  }
};