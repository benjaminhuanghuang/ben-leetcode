/*
860. Lemonade Change

Level: Easy

https://leetcode.com/problems/lemonade-change
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
  bool lemonadeChange(vector<int> &bills)
  {
    int fiveBill = 0;
    int tenBill = 0;
    for (int i = 0; i < bills.size(); i++)
    {
      if (bills[i] == 5)
      {
        fiveBill++;
      }
      else if (bills[i] == 10)
      {
        if (fiveBill <= 0)
          return false;
        fiveBill--;
        tenBill++;
      }
      else if (bills[i] == 20)
      {
        if (tenBill > 0 && fiveBill > 0)
        {
          tenBill--;
          fiveBill--;
        }
        else if (fiveBill >= 3)
        {
          fiveBill -= 3;
        }
        else
          return false;
      }
    }

    return true;
  }
};