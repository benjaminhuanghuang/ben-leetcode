/*
313. Super Ugly Number

Level: Medium

https://leetcode.com/problems/super-ugly-number
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
  https://zxi.mytechroad.com/blog/math/leetcode-313-super-ugly-number/

  Priority Queue

  Time complexity: O(nlogn)
  Space complexity: O(n)
*/
struct Node
{
  int num;
  int index;
  int prime;

  bool operator>(const Node &o) const
  {
    if (this->num == o.num)
      return this->index > o.index;
    return this->num > o.num;
  }
};

class Solution
{
public:
  int nthSuperUglyNumber(int n, vector<int> &primes)
  {
    if (n == 1)
      return 1;
    vector<int> nums(n, 1);
    priority_queue<Node, vector<Node>, greater<Node>> q;
    for (int p : primes)
      q.push({p, 1, p});
    for (int i = 1; i < n; ++i)
    {
      nums[i] = q.top().num;
      while (nums[i] == q.top().num)
      {
        Node node = std::move(q.top());
        q.pop();
        node.num = nums[node.index++] * node.prime;
        q.push(std::move(node));
      }
    }
    return nums.back();
  }
};