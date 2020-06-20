/*
1154. Day of the Year

Level: Easy

https://leetcode.com/problems/day-of-the-year
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

class Solution {
public:
    int dayOfYear(string date) {
      int year = stoi(date.substr(0,4));
      int month = stoi(date.substr(5,2));
      int day = stoi(date.substr(8,2));

      int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


      for(int i = 1; i <= month; i++)
      {
        day +=  days[i -1];
        if(i == 2 && ((year % 4==0 && year%100!=0) || year %400 ==0))
        {
          day ++;
        }
      }
      return day;
    }
};