/*
717. 1-bit and 2-bit Characters
https://leetcode.com/problems/1-bit-and-2-bit-characters/
*/

#include <vector>

using namespace std;

/*
https://www.cnblogs.com/grandyang/p/7790029.html
这道题说有两种特殊的字符，一种是两位字符，只能是二进制的11和10，另一种是单个位字符，只能是二进制的0。
现在给了我们一个只包含0和1的数组，问我们能否将其正确的分割，使得最后一个字符是个单个位字符。
这道题可以使用贪婪算法来做，因为两种字符互不干扰，只要我们遍历到了数字1，那么其必定是两位字符，
所以后面一位也得跟着，而遍历到了数字0，那么就必定是单个位字符。所以我们可以用一个变量i来记录当前遍历到的位置，
如果遇到了0，那么i自增1，如果遇到了1，那么i自增2，我们循环的条件是i < n-1，即留出最后一位，
所以当循环退出后，当i正好停留在n-1上，说明最后一位是单独分割开的，因为题目中限定了最后一位一定是0，
所以没必要再判断了：
*/
class Solution
{
public:
  bool isOneBitCharacter(vector<int> &bits)
  {
    int n = bits.size(), i = 0;
    while (i < n - 1)
    {
      if (bits[i] == 0)
        ++i;
      else
        i += 2;
    }
    return i == n - 1;
  }
};
/*
 题目的意思是要判断最后一个0元素是属于0还是输入10；
    遍历数组，给定指针，若当前位为1则指针+2；若当前位为0，则指针+1；
    判断最后指针是否与bits.length-1相等，相等则为真，否则为假；其中length=1的情况也包括进去了。
   
*/
class Solution2
{
public:
  bool isOneBitCharacter(vector<int> &bits)
  {
    int i = 0;
    while (i < bits.size() - 1)
    {
      if (bits[i] == 1)
      {
        i += 2;
      }
      else
      {
        i++;
      }
    }
    return i == bits.size() - 1;
  }
};