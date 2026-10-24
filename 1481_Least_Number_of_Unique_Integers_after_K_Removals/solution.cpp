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

class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    unordered_map<int, int> c;
    for (int x : arr)
      ++c[x];
    vector<int> m; // freq
    for (const auto [x, f] : c)
      m.push_back(f);
    sort(begin(m), end(m));
    int ans = m.size();
    int i = 0;
    while (k--)
    {
      if (--m[i] == 0)
      {
        ++i;
        --ans;
      }
    }
    return ans;
  }
};