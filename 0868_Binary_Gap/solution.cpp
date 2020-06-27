/*
868. Binary Gap

Level: Easy

https://leetcode.com/problems/binary-gap
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
  int binaryGap(int N)
  {
    int maxDis = 0;
    int bit = 0;         // current bit
    int lastOnePos = -1; // position of last bit 1

    while (N > 0)
    {
      int lastBit = N & 1;
      if (lastBit == 1)
      {
        if (lastOnePos == -1)
          lastOnePos = bit;
        // distance between two consecutive 1's, 1 and next 1
        maxDis = max(maxDis, bit - lastOnePos);
        lastOnePos = bit;
      }
      N >>= 1;
      bit++;
    }

    return maxDis;
  }
};