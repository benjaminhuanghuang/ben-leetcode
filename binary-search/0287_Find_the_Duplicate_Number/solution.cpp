/*
287. Find the Duplicate Number

https://leetcode.com/problems/find-the-duplicate-number/
*/
#include <vector>
#include <numeric>
using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-287-find-the-duplicate-number/
 //时间 O(NlogN) 空间 O(1)
    //二分查找,    1..10, 小于等于5的一定有5个,如果多于5个,就在lower part, 等于5个就是upper part.
    // Find the smallest m such that len(nums <= m) > m, which means m is the duplicate number.
   
*/
class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int l = 1;
    int r = nums.size();
    while (l < r)
    {
      int m = (r - l) / 2 + l;
      int count = 0; // len(nums <= m)
      for (int num : nums)
        if (num <= m)
          ++count;

      if (count <= m)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};