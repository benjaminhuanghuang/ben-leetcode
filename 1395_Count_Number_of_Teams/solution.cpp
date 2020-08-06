/*
1395. Count Number of Teams

Level: Medium

https://leetcode.com/problems/count-number-of-teams
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
    Time complexity: O(n^3)
    Space complexity: O(1)
*/

class Solution_BruteForce
{
public:
  int numTeams(vector<int> &rating)
  {
    int n = rating.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
          if (rating[i] < rating[j] && rating[j] < rating[k] || rating[i] > rating[j] && rating[j] > rating[k])
            ++ans;
    return ans;
  }
};

/*
  Solution 2: Math

  For each soldier j, count how many soldiers on his left has smaller ratings as left[j], count how many soldiers his right side has larger ratings as right[j]

  ans = sum(left[j] * right[j] + (j – left[j]) * (n – j – 1 * right[j])

  Time complexity: O(n^2)
  Space complexity: O(1)
*/
class Solution {
public:
  int numTeams(vector<int>& rating) {
    int n = rating.size();
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      int l = 0;
      int r = 0;
      for (int i = 0; i < j; ++i)
        if (rating[i] < rating[j]) ++l;
      for (int k = j + 1; k < n; ++k)
        if (rating[j] < rating[k]) ++r;
      ans += (l * r) + (j - l) * (n - j - 1 - r);
    }  
    return ans;
  }
};