/*
166. Fraction to Recurring Decimal

Level: Medium

https://leetcode.com/problems/fraction-to-recurring-decimal
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
*/

class Solution
{
public:
  string fractionToDecimal(int numerator, int denominator)
  {
    if (numerator == 0)
      return "0";
    // abs(int_min) case overflow
    long numer = long(numerator);
    long denom = long(denominator);
    if (numer % denom == 0)
      return to_string(numer / denom);

    int sign = 1;
    if ((numer < 0 && denom > 0) || (numer > 0 && denom < 0))
      sign = -1;
    numer = abs(numer);
    denom = abs(denom);

    // get integer part
    string temp = "";
    if (sign == -1)
      temp = "-" + to_string(numer / denom) + ".";
    else
      temp = to_string(numer / denom) + ".";

    long temp_num = (numer % denom);
    int pos = temp.length();
    int break_pos = -1;
    unordered_map<long, int> track;   // key: temp_num, val: position
    while (temp_num != 0 && break_pos == -1)
    {
      temp_num *= 10;
      if(track.count(temp_num))
      {
        break_pos = track[temp_num];
        break;
      }
      track[temp_num] = pos++;
     
      temp += to_string(temp_num / denom);
      temp_num = temp_num % denom;
    }
    if (break_pos != -1)
      return (temp.substr(0, break_pos) + "(" + temp.substr(break_pos, pos - break_pos) + ")");
    return temp;
  }
};