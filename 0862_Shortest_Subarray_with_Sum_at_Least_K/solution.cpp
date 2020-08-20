/*
862. Shortest Subarray with Sum at Least K

Level: Hard

https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k
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
  求最短的子数组长度，使得这个子数组的和最少为K，如果不存在这样的子数组，返回-1.
*/

class Solution
{
public:
  int shortestSubarray(vector<int> &A, int K)
  {
    int N = A.size();
    vector<int> P(N + 1); // prefix sum
    for (int i = 0; i < N; ++i)
      P[i + 1] = P[i] + (long)A[i];

    // Want smallest y-x with P[y] - P[x] >= K
    int ans = N + 1;  // N+1 is impossible
    deque<int> monoq; //opt(y) candidates, as indices of P
    int tmp;

    for (int y = 0; y < P.size(); ++y)
    {
      // Want opt(y) = largest x with P[x] <= P[y] - K;
      while (!monoq.empty() && P[y] <= P[monoq.back()])
      {
        monoq.pop_back();
      }
      while (!monoq.empty() && P[y] >= P[monoq.front()] + K)
      {
        tmp = monoq.front();
        monoq.pop_front();
        ans = min(ans, y - tmp);
      }

      monoq.push_back(y);
    }

    return ans < N + 1 ? ans : -1;
  }
};