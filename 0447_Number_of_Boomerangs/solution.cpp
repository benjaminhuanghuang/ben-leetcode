/*
447. Number of Boomerangs

Level: Easy

https://leetcode.com/problems/number-of-boomerangs
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
private:
  int getDistance(vector<int> point1, vector<int> point2)
  {
    int distance = pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2);
    return distance;
  }

public:
  int numberOfBoomerangs(vector<vector<int>> &points)
  {
    // 存储距离和这个距离出现的次数。
    unordered_map<int, int> map;
    int res = 0;
    for (int i = 0; i < points.size(); i++)
    {
      for (int j = 0; j < points.size(); j++)
      {
        if (i == j)
          continue;

        int distance = getDistance(points[i], points[j]);
        map[distance]++;
      }
      for (auto kv : map)
      {
        //要依次选择每个点当做第一个点,排列组合结果数
        res += kv.second * (kv.second - 1);
      }
      map.clear();
    }
    return res;
  }
};