/*
1185. Day of the Week

Level: Easy

https://leetcode.com/problems/day-of-the-week
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
private:
  bool isLeap(int year)
  {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  }
public:
  string dayOfTheWeek(int day, int month, int year)
  {
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dayofweek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int sum = 4; //because 31 december 1970 was thursday(4th day)

    // add year
    for (int i = 1971; i < year; i++)
    {
      if (isLeap(i))
      {
        sum += 366;
      }
      else
      {
        sum += 365;
      }
    }
    // add month
    for (int i = 1; i < month; i++)
    {
      if (i == 2 && isLeap(year))
      {
        sum++;
      }
      sum += months[i];
    }
    // add day
    sum += day;
    
    return dayofweek[sum % 7];
  }
};