/*
421. Maximum XOR of Two Numbers in an Array

Level: Medium

https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.youtube.com/watch?v=blsm1fA9JHQ

  //利用XOR的性质，a^b = c, 则有 a^c = b，且 b^c = a;

  //所以每次从高位开始，到某一位为止，所能获得的最大的
  //假定在某一位上的任意两数xor能得到的最大值是tmp,那么他一定满足a(xor)b = tmp,
  //其中set.contains(a) && set.contains(b). 所以，我们只需要判断b(xor)tmp的结果是不是在当前这一位下的set内，
  //就可以知道这个tmp能不能由这个set中的任意两个数组成。
  // example: Given [14, 11, 7, 2], which in binary are [1110, 1011, 0111, 0010].
  // Since the MSB is 3, I'll start from i = 3 to make it simplify.
  // i = 3, set = {1000, 0000}, max = 1000
  // i = 2, set = {1100, 1000, 0100, 0000}, max = 1100
  // i = 1, set = {1110, 1010, 0110, 0010}, max = 1100
  // i = 0, set = {1110, 1011, 0111, 0010}, max = 1100

*/

class Solution
{
public:
  int findMaximumXOR(vector<int> &nums)
  {
    int max = 0, mask = 0;
    // 从高位向低位找
    for (int i = 31; i >= 0; i--)
    {
      mask = mask | (1 << i);
      unordered_set<int> s;
      for (int num : nums)
      {
        s.insert(num & mask);
      }

      int tmp = max | (1 << i);
      for (int prefix : s)
      {
        if (s.count(prefix ^ tmp))
        {
          max = tmp;
          break;     // 从高位向低位找，一旦找到就返回
        }
      }
    }
    return max;
  }
};