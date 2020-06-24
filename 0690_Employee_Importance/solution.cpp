/*
690. Employee Importance

Level: Easy

https://leetcode.com/problems/employee-importance
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

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Employee
{
public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution
{
public:
  int getImportance(vector<Employee *> employees, int id)
  {
    unordered_map<int, Employee *> map;

    for (auto e : employees)
      map[e->id] = e;

    return dfs(id, map);
  }

  int dfs(int id, unordered_map<int, Employee *> &map)
  {
    Employee *e = map[id];

    if (e->subordinates.empty())
      return e->importance;

    int imp = e->importance;

    for (int sub : e->subordinates)
      imp += dfs(sub, map);

    return imp;
  }
};