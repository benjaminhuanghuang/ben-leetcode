/*
1337. The K Weakest Rows in a Matrix

Level: Easy

https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>

#include <algorithm>
#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
  {
    vector<pair<int, int>> counts; // index, count
    for (int i = 0; i < mat.size(); i++)
    {
      counts.push_back({i, (int)count(mat[i].begin(), mat[i].end(), 1)});
    }
    // cmp: The value returned indicates whether the first argument is considered to go before the second
    sort(counts.begin(), counts.end(), [](pair<int, int> &a, pair<int, int> &b) {
      if (a.second == b.second)
      {
        return a.first < b.first;
      }
      return a.second < b.second;
    });
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
      ans.push_back(counts[i].first);
    }
    return ans;
  }

  /*
    Better space complexity
  */
  vector<int> kWeakestRows_v2(vector<vector<int>> &mat, int k)
  {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res(m, 0);
    vector<int> counts(m, 0);
    iota(res.begin(), res.begin() + m, 0);

    for (int i = 0; i < mat.size(); ++i)
      for (int j = 0; j < mat[0].size(); ++j)
        if (mat[i][j] == 0)
          ++counts[i];

    const static auto cmp = [&](const int &x, const int &y) {
      if (counts[x] == counts[y])
        return x < y;
      return counts[x] > counts[y];
    };

    sort(res.begin(), res.end(), cmp);

    while (res.size() != k)
      res.pop_back();

    return res;
  }
};