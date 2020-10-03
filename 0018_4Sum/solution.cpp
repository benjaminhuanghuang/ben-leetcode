/*
18. 4Sum

https://leetcode.com/problems/4sum/
*/

#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-18-4sum/
Solution 2: Sorting + HashTable

Time complexity: O(n^3 + klogk)

Space complexity: O(n + k)
*/
class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &num, int target)
  {
    sort(num.begin(), num.end());
    if (target > 0 && target > 4 * num.back())
      return {};
    if (target < 0 && target < 4 * num.front())
      return {};

    unordered_map<int, int> index;
    for (int i = 0; i < num.size(); ++i)
      index[num[i]] = i;

    set<vector<int>> h;
    int n = num.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          int t = target - num[i] - num[j] - num[k];
          if (t < num[k])
            break;
          auto it = index.find(t);
          if (it == index.end() || it->second <= k)
            continue;
          h.insert({num[i], num[j], num[k], t});
        }
      }
    }

    return vector<vector<int>>(begin(h), end(h));
  }
};

/*
https://www.youtube.com/watch?v=YkxsyPItHeM
Similar to #15. 3Sum

Time complexity: O(n^3)

Space complexity:
*/
class Solution2
{
public:
  vector<vector<int>> fourSum(vector<int> &num, int target)
  {
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    int n = num.size();
    for (int i = 0; i < n - 3; i++)
    {
      if (i > 0 && num[i] == num[i - 1]) // skip repeat number
        continue;

      for (int j = i + 1; j < n - 2; j++)
      {
        if (j > i + 1 && num[j] == num[j - 1])
          continue;
        int l = j + 1, r = n - 1;
        while (l < r)
        {
          int sum = num[i] + num[j] + num[l] + num[r];
          if (sum == target)
          {
            ans.push_back({num[i], num[j], num[l], num[r]});
            while (l < r && num[l] == num[l + 1])
              l++;
            while (l < r && num[r] == num[r - 1])
              r--;
            l++;
            r--;
          }
          else if (sum < target)
          {
            l++;
          }
          else
          {
            r--;
          }
        }
      }
    }

    return ans;
  }
};