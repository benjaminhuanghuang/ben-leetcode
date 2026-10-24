/*
347. Top K Frequent Elements

Level: Medium

https://leetcode.com/problems/top-k-frequent-elements

- 692. Top K Frequent Words
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  /*
    Priority queue

    Time complexity: O(n) + O(nlogk)
    Space complexity: O(n)

    - 692. Top K Frequent Words
    */
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> count;
    for (const int num : nums) // num: count
      ++count[num];
    priority_queue<pair<int, int>> q;  // from small to large, ordered by first element

    // Sort by frequency
    for (const auto &pair : count)
    {
      q.emplace(-pair.second, pair.first);   // emplace a pair
      if (q.size() > k)
        q.pop();
    }
    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
      ans.push_back(q.top().second);
      q.pop();
    }
    return ans;
  }

  /*
    Bucket Sort
    
    Time complexity: O(n)

    Space complexity: O(n)
    */
  vector<int> topKFrequent_V2(vector<int> &nums, int k)
  {
    unordered_map<int, int> count;             // num: frequent
    int max_freq = 1;
    //O(N)
    for (const int num : nums)
      max_freq = max(max_freq, ++count[num]);

    unordered_map<int, vector<int>> buckets;   // frequent: num
    for (const auto &kv : count)
      buckets[kv.second].push_back(kv.first);
    vector<int> ans;
    for (int i = max_freq; i >= 1; --i)
    {
      auto it = buckets.find(i);
      if (it == buckets.end())
        continue;
      ans.insert(ans.end(), it->second.begin(), it->second.end());  
      if (ans.size() == k)
        return ans;
    }
    return ans;
  }
};