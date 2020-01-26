/*

229. Majority Element II

https://leetcode.com/problems/majority-element-ii/
*/
#include <vector>

using namespace std;

/*
  http://www.cnblogs.com/grandyang/p/4606822.html
   任意一个数组出现次数大于n/3的众数最多有两个
*/

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    vector<int> res;
    int m = 0, n = 0, cm = 0, cn = 0;
    for (int num : nums)
    {
      if (num == m)
        ++cm;
      else if (num == n)
        ++cn;
      else if (cm == 0)
      {
        m = num;
        cm = 1;
      }
      else if (cn == 0)
      {
        n = num;
        cn = 1;
      }
      else
      {
        --cm;
        --cn;
      }
    }
    cm = cn = 0;
    for (int num : nums)
    {
      if (num == m)
        ++cm;
      else if (num == n)
        ++cn;
    }
    if (cm > nums.size() / 3)
      res.push_back(m);
    if (cn > nums.size() / 3)
      res.push_back(n);
    return res;
  }
};