/*
1184. Distance Between Bus Stops

Level: Easy

https://leetcode.com/problems/distance-between-bus-stops
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  注意 可能 start > destination
*/

class Solution
{
public:
  int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
  {
    if (start > destination)
      return distanceBetweenBusStops(distance, destination, start);
    int total = accumulate(distance.begin(), distance.end(), 0);
    int d = 0;
    for (int i = start; i < destination; i++)
    {
      d += distance[i];
    }

    return min(total - d, d);
  }
};