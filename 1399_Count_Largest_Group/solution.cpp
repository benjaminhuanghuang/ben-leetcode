/*
1399. Count Largest Group

Level: Easy

https://leetcode.com/problems/count-largest-group
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
  int countLargestGroup(int n)
  {
    // because 1 <= n <= 10^4
    vector<int> c(37); // max sum is 9+9+9+9 = 36
    for (int i = 1; i <= n; ++i)
    {
      int x = i;
      int sum = countDigits(x);
      ++c[sum];
    }
    return count(begin(c), end(c), *max_element(begin(c), end(c)));
  }

private:
  int countDigits(int n)
  {
    int sum = 0;
    while (n)
    {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
};