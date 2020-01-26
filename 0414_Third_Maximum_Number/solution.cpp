/*
414. Third Maximum Number
https://leetcode.com/problems/third-maximum-number/
*/
#include <vector>
#include <set>
using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/array/leetcode-414-third-maximum-number/
*/

class Solution
{
public:
  int thirdMax(vector<int> &nums)
  {
    set<int> s;
    for (int num : nums)
    {
      s.insert(num);
      if (s.size() > 3)
        s.erase(s.begin());
    }
    //rbegin() instead of end() - 1
    return s.size() != 3 ? *s.rbegin() : *s.begin();
  }
};
// Error [1,2,-2147483648]
// 初始化要用长整型long的最小值，否则当数组中有INT_MIN存在时，就不知道该返回INT_MIN还是最大值first了        
class Solution2
{
public:
  int thirdMax(vector<int> &nums)
  {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for (int num : nums)
    {
      if (num > first)
      {
        third = second;
        second = first;
        first = num;
      }
      else if (num > second && num < first)
      {
        third = second;
        second = num;
      }
      else if (num > third && num < second)
      {
        third = num;
      }
    }
    int res = (third == INT_MIN || third == INT_MIN) ? first : third;
    return res;
  }
};