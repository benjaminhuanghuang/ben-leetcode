/*
373. Find K Pairs with Smallest Sums

Level: Medium

https://leetcode.com/problems/find-k-pairs-with-smallest-sums
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

struct Node
{
  int sum, i, j;
  Node(int sum, int i, int j) : sum(sum), i(i), j(j) {}
  bool operator<(const Node &b) const
  {
    return sum > b.sum;
  }
};

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    vector<vector<int>> ans;
    if (nums1.empty() || nums2.empty())
      return ans;
    // 将nums1中每个数和nums2的第一个数放进堆
    priority_queue<Node> q;
    for (int i = 0; i < k && i < nums1.size(); ++i)
      q.push(Node(nums1[i] + nums2[0], i, 0));      // sum desending

    // try more
    while (k-- && !q.empty())
    {
      Node cur = q.top();
      q.pop();
      ans.push_back({nums1[cur.i], nums2[cur.j]});
      if (cur.j + 1 < nums2.size())
        q.push(Node(nums1[cur.i] + nums2[cur.j + 1], cur.i, cur.j + 1));
    }
    return ans;
  }
};