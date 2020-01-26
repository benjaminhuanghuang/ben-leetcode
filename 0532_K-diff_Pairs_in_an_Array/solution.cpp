/*
532. K-diff Pairs in an Array
https://leetcode.com/problems/k-diff-pairs-in-an-array/
*/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    if(k < 0)
      return 0;
    unordered_map<int, int> numCounts;
    for (auto &n : nums)
    {
      numCounts[n]++;
    }
    int pairs = 0;
    for (auto &kv : numCounts)
    {
      if (k == 0)
      {
        if (kv.second >= 2)
          pairs++;
      }
      else
      {
        pairs += numCounts.count(kv.first - k);
      }
    }
    return pairs;
  }
};