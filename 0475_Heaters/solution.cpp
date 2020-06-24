/*
475. Heaters

Level: Easy

https://leetcode.com/problems/heaters
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
  找到一个 最小 半径使得加热器覆盖所有房子, 即找到加热器和房子的 最大 距离
  找到每一个房子最近的暖气的距离 然后取这些距离的最大值
*/

class Solution
{
public:
  /*
      

      注意：先排序 然后使用贪婪策略寻找当前最优质 
          abs(houses[i] - heaters[j]) 与 abs(houses[i] - heaters[j + 1])比较
      如果 abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]) , j++再次进行比较
      如果 abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j + 1]) , 当前第j个暖气距离第i个房间最近,更新最大值
    */
  int findRadius(vector<int> &houses, vector<int> &heaters)
  {
    // sort
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int j = 0;
    int mixDistance = -1;
    for (int i = 0; i < houses.size(); i++)
    {
      // 找到离房子i最近的暖气j的距离 然后取这些距离的最大值
      if ((j + 1 < heaters.size()) && (abs(houses[i] - heaters[j+1]) <= abs(houses[i] - heaters[j])))
      {
        j++;
        i--;   // i 保持不变
      }
      else
      {
        if (mixDistance < abs(houses[i] - heaters[j]))
        {
          mixDistance = abs(houses[i] - heaters[j]);
        }
      }
    }
    return mixDistance;
  }
};