/*
1491. Average Salary Excluding the Minimum and Maximum Salary

Level: Easy

https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
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
  double average(vector<int> &salary)
  {
    int minSalary = INT_MAX;
    int maxSalary = INT_MIN;

    double sum = 0;
    for (int s : salary)
    {
      if (s > maxSalary)
        maxSalary = s;
      if (s < minSalary)
        minSalary = s;
      sum += s;
    }

    return (sum - minSalary - maxSalary) / (salary.size() - 2);
  }
};