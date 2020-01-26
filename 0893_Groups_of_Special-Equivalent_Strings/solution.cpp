/*
893. Groups of Special-Equivalent Strings

https://leetcode.com/problems/groups-of-special-equivalent-strings/
*/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
可以对一个字符串的所有奇数位置或者偶数位置进行任意的调换顺序。如果两个字符串在经历了上面的操作之后，
可以做到完全相等，那么就属于题目中的一个组。现在就要我们求最终分为几个组。

把这个数组中所有的奇数位置和偶数位置的字符分别取出来，进行排序再合并。把合并之后的结果放入到一个set里，
然后统计set中字符串的个数也就是题目中要求的组数。
*/
class Solution
{
public:
  int numSpecialEquivGroups(vector<string> &A)
  {
    unordered_set<string> s;
    for (const string &a : A)
    {
      string odd;
      string even;
      for (int i = 0; i < a.size(); ++i)
      {
        if (i % 2)
          odd += a[i];
        else
          even += a[i];
      }
      sort(begin(odd), end(odd));
      sort(begin(even), end(even));
      s.insert(odd + even);
    }
    return s.size();
  }
};