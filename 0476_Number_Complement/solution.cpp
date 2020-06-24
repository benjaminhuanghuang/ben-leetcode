/*
476. Number Complement

Level: Easy

https://leetcode.com/problems/number-complement
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
  int findComplement(int num)
  {
    unsigned maskCreater = 1, temp = num;   
    while (temp > 0)
    {
      maskCreater = maskCreater << 1;
      temp = temp >> 1;
    }
    // int maskCreater cause overflow here!
    int mask = maskCreater - 1;
    return num ^ mask;
  }
};