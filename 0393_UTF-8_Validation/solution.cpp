/*
393. UTF-8 Validation

Level: Medium

https://leetcode.com/problems/utf-8-validation
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
  https://www.youtube.com/watch?v=0s4M9Y1ue5o

  data >> k = mask        k = 8 - len(mask)
*/

class Solution
{
public:
  bool validUtf8(vector<int> &data)
  {
    int left = 0; // how many bytes need check. left =0 means it is first char
    for (int d : data)
    {
      if (left == 0)
      {
        // check the fisrt charactor
        if ((d >> 3) == 0b11110)   // 4 bytes
          left = 3;
        else if ((d >> 4) == 0b1110)   // 3 bytes
          left = 2;
        else if ((d >> 5) == 0b110)
          left = 1;
        else if ((d >> 7) == 0b0)
          left = 0;
        else
          return false;
      }
      else
      {
        // check the following charactor:  10xxxxxx
        if ((d >> 6) != 0b10)
          return false;
        --left;
      }
    }
    return left == 0;
  }
};