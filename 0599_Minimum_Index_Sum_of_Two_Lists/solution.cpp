/*
599. Minimum Index Sum of Two Lists

Level: Easy

https://leetcode.com/problems/minimum-index-sum-of-two-lists
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
  给两个字符串数组，找到坐标位置之和最小的相同的字符串。
  对于这种数组项和其坐标之间关系的题，最先考虑的就是要建立数据和其位置坐标之间的映射。
  我们建立list1的值和坐标的之间的映射，然后遍历list2，如果当前遍历到的字符串在list1中也出现了，那么我们计算两个的坐标之和，
  如果跟我们维护的最小坐标和mn相同，那么将这个字符串加入结果res中，如果比mn小，那么mn更新为这个较小值，然后将结果res清空并加入这个字符串：
 
*/

class Solution
{
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
  {
    vector<string> minRes;
    unordered_map<string, int> map1;
    unordered_map<string, int> map2;

    int min = INT_MAX;

    for (int i = 0; i < list1.size(); i++)
    {
      map1.insert({list1[i], i});
    }
    for (int i = 0; i < list2.size(); i++)
    {
      map2.insert({list2[i], i});
    }

    for (int i = 0; i < list1.size(); i++)
    {
      // 如果map2 也包含 这个restaurant/map1的key
      if (map2.count(list1[i]))
      {
        int sum = map1[list1[i]] + map2[list1[i]];
        if (sum < min)
        {
          min = sum;
          // minRes始终存储最小的sum，如果有比这个min小的sum,更新并且重置minRes
          minRes.clear();
          minRes.push_back(list1[i]);
        }
        else if (sum == min)
        {
          minRes.push_back(list1[i]);
        }
      }
    }

    return minRes;
  }
};