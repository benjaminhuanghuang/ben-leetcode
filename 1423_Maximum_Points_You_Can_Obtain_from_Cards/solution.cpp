/*
1423. Maximum Points You Can Obtain from Cards

Level: Medium

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
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
  cur： 如果全部从头部开始拿，会得多少分
  每次换一张牌，比较大小
*/

class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    const int n = cardPoints.size();
    int cur = accumulate(begin(cardPoints), begin(cardPoints) + k, 0);
    int ans = cur;
    for (int i = 0; i < k; ++i)
    {
      cur = cur - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
      ans = max(ans, cur);
    }
    return ans;
  }
};