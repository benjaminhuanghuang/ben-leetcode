/*
973. K Closest Points to Origin

Level: Medium

https://leetcode.com/problems/k-closest-points-to-origin
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
  Sort
    Time complexity: O(nlogn)
    Space complexity: O(n)
*/

class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
  {
    /*
      修改了input， 是一个缺点
    */
    std::sort(begin(points), end(points), [](vector<int> &a, vector<int> &b) {
      return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    });

    return vector<vector<int>>(points.begin(), points.begin() + K);
  }
};

/*
  https://www.youtube.com/watch?v=zWiB3RGa-vo
*/
class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
  {
    vector<long> s(points.size());
    for (int i = 0; i < points.size(); ++i)
    {
      s[i] = (static_cast<long>(points[i][0] * points[i][0] +
                                points[i][1] * points[i][1])
              << 32) |
             i;
    }
    std::sort(begin(s), end(s));

    vector<vector<int>> ans(K);
    for (int i = 0; i < K; ++i)
      ans[i] = points[static_cast<int>(s[i])];
    return ans;
  }
};