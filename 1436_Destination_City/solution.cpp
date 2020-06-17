/*
1436. Destination City

Level: Easy

https://leetcode.com/problems/destination-city
*/
#include <vector>
#include <string>
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
  string destCity(vector<vector<string>> &paths)
  {
    unordered_set<string> s;

    for (const auto &v : paths)
      s.insert(v[0]);

    for (const auto &v : paths)
      if (s.find(v[1]) == s.end())
        return v[1];

    return "";
  }
};