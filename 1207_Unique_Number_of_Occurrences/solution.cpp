/*
1207. Unique Number of Occurrences

Level: Easy

https://leetcode.com/problems/unique-number-of-occurrences
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  bool uniqueOccurrences(vector<int> &arr)
  {
    unordered_map<int, int> counter;
    for (int i : arr)
    {
      counter[i]++;
    }

    unordered_set<int> s;
    for (auto kv : counter)
    {
      s.insert(kv.second);
    }
    return s.size() == counter.size();
  }
};