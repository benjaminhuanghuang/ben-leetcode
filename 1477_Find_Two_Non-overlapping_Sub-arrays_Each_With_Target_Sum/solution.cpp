/*
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

Level: Medium

https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum
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
  https://zxi.mytechroad.com/blog/sliding-window/leetcode-1477-find-two-non-overlapping-sub-arrays-each-with-target-sum/
*/

class Solution
{
public:
  int minSumOfLengths(vector<int> &arr, int target)
  {
    constexpr int kInf = 1e9;
    const int n = arr.size();
    // min_lens[i] := min length of a valid subarray ends or before i.
    vector<int> min_lens(n, kInf);
    int ans = kInf;
    int sum = 0;
    int s = 0;
    int min_len = kInf;
    for (int e = 0; e < n; ++e)
    {
      sum += arr[e];
      while (sum > target)
        sum -= arr[s++];
      if (sum == target)
      {
        const int cur_len = e - s + 1;
        if (s > 0 && min_lens[s - 1] != kInf)
          ans = min(ans, cur_len + min_lens[s - 1]);
        min_len = min(min_len, cur_len);
      }
      min_lens[e] = min_len;
    }
    return ans >= kInf ? -1 : ans;
  }
};