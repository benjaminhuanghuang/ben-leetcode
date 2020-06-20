/*
1304. Find N Unique Integers Sum up to Zero

Level: Easy

https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
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
  vector<int> sumZero(int n)
  {
    vector<int> ans;
    if (n & 1) //odd
    {
      ans.push_back(0);
    }
    for (int i = 1; i <= n / 2; i++)
    {
      ans.push_back(i);
      ans.push_back(-i);
    }
    return ans;
  }
};