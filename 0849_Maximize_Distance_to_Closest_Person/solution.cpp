/*
849. Maximize Distance to Closest Person
https://leetcode.com/problems/maximize-distance-to-closest-person/
*/
#include <vector>
#include <string>

using namespace std;
/*
https://www.cnblogs.com/grandyang/p/10503789.html

双指针，start 指向连续0的起点，初始化为0，i为当前遍历到的位置。
遍历 seats 数组，跳过0的位置，
当遇到1的时候，此时我们先判断下 start 的值，若是0的话，表明当前这段连续的空位是靠着墙的，所以我们要用连续空位的长度 i-start 
来直接更新结果res，否则的话就是两头有人的中间的空位，那么用长度加1除以2来更新结果res，
此时 start 要更新为 i+1，指向下一段连续空位的起始位置。
for循环退出后，还是要处理最右边靠墙的位置，用 n-start 来更新结果res即可
*/
class Solution
{
public:
  int maxDistToClosest(vector<int> &seats)
  {
    int startOfZero = 0;

    int res = 0, n = seats.size();

    for (int i = 0; i < n; ++i)
    {
      // skip the 0s
      if (seats[i] == 1)
      {
        if (startOfZero == 0)
        {
          // startOfZero is 0，means 当前这段连续的空位是靠着墙的，所以我们要用连续空位的长度 i-start  
          res = max(res, i - startOfZero);
        }
        else
          res = max(res, (i - startOfZero + 1) / 2);
        startOfZero = i + 1;
      }
    }
    res = max(res, n - startOfZero);
    return res;
  }
};