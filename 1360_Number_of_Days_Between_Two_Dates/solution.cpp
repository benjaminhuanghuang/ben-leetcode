/*
1360. Number of Days Between Two Dates

Level: Easy

https://leetcode.com/problems/number-of-days-between-two-dates
*/
#include <array>
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
  int daysBetweenDates(string date1, string date2)
  {
    array<int, 12> daysOfMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto isLeap = [](int year) {
      return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    };

    auto daysFromEpoch = [&](const string &date) {
      int year = stoi(date.substr(0, 4));
      int month = stoi(date.substr(5, 2));
      int days = stoi(date.substr(8, 2));
      for (int i = 1970; i < year; ++i)
        days += 365 + isLeap(i);  // +1 if isLeap()
      for (int i = 1; i < month; ++i)
        days += daysOfMonth[i - 1];
      days += month > 2 && isLeap(year);
      return days;
    };
    return abs(daysFromEpoch(date1) - daysFromEpoch(date2));
  }
};