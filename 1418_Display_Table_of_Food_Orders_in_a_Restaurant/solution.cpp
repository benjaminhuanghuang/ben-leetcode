/*
1418. Display Table of Food Orders in a Restaurant

Level: Medium

https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
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
  vector<vector<string>> displayTable(vector<vector<string>> &orders)
  {
    map<int, unordered_map<string, int>> table_foods;
    set<string> menus;

    for (auto &order : orders)
    {
      table_foods[stoi(order[1])][order[2]]++;
      menus.insert(order[2]);
    }

    vector<vector<string>> res;

    vector<string> titles;
    titles.push_back("Table");
    titles.insert(titles.end(), menus.begin(), menus.end());
    res.push_back(titles);

    for (auto &table : table_foods)
    {
      vector<string> ans;
      ans.push_back(to_string(table.first));
      for (auto &food : menus)
      {
        if (table.second.count(food))
        {
          ans.push_back(to_string(table.second[food]));
        }
        else
        {
          ans.push_back("0");
        }
      }
      res.push_back(ans);
    }

    return res;
  }
};