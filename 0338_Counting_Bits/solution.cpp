/*
338. Counting Bits

Level: Medium

https://leetcode.com/problems/counting-bits
*/
#include <vector>
#include <string>
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
  /*
   For number 2(10), 4(100), 8(1000), 16(10000), ..., the number of 1's is 1.
   Any other number can be converted to be 2^m + x. 
   For example, 9=8+1, 10=8+2. The number of 1's for any other number is 1 + count of 1's in x.
  */
  vector<int> countBits(int num)
  {
    vector<int> result(num + 1);

    int p = 1; //p tracks the index for number x
    int pow = 1;   // 1, 2, 4, 6, 8....
    for (int i = 1; i <= num; i++)
    {
      if (i == pow)
      {
        result[i] = 1;
        pow <<= 1;
        p = 1;
      }
      else
      {
        result[i] = result[p] + 1;
        p++;
      }
    }
    return result;
  }
  /*
    https://www.cnblogs.com/grandyang/p/5294255.html

    从1开始，遇到偶数时，其1的个数和该偶数除以2得到的数字的1的个数相同，遇到奇数时，其1的个数等于该奇数除以2得到的数字的1的个数再加1：
  */
  vector<int> countBits_V2(int num)
  {
    vector<int> result(num + 1);
    for (int i = 1; i <= num; i++)
    {
      result[i] = result[i >> 1] + (i & 1);
    }
    return result;
  }
};