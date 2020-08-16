/*
1093. Statistics from a Large Sample

Level: Medium

https://leetcode.com/problems/statistics-from-a-large-sample
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
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
  vector<double> sampleStats(vector<int> &count)
  {
    int counts = 0;
    double minVal = 255;
    double maxVal = 0;
    double mode = -1;
    int modeCount = 0;
    long sum = 0;
    map<int, int> m;
    for (int i = 0; i <= 255; ++i)
    {
      if (!count[i])
        continue;
      sum += static_cast<long>(i) * count[i];
      minVal = min(minVal, (double)i);
      maxVal = max(maxVal, (double)i);
      if (count[i] > modeCount)
      {
        mode = i;
        modeCount = count[i];
      }
      m[counts += count[i]] = i;
    }
    auto it1 = m.lower_bound(counts / 2);
    double median = it1->second;
    auto it2 = next(it1);
    if (counts % 2 == 0 && it2 != m.end() && it1->first == counts / 2)
    {
      median = (median + it2->second) / 2;
    }
    return {minVal, maxVal, static_cast<double>(sum) / counts, median, mode};
  }
};