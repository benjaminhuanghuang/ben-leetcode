/*
1232. Check If It Is a Straight Line

Level: Easy

https://leetcode.com/problems/check-if-it-is-a-straight-line
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <climits>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
private:
  float getSlop(vector<int> &c2, vector<int> &c1)
  {
    return c1[0] == c2[0] ? INT_MAX : float(c2[1] - c1[1]) / (c2[0] - c1[0]);
  }

public:
  bool checkStraightLine(vector<vector<int>> &coordinates)
  {
    if (coordinates.size() < 3)
      return true;
    float slope = getSlop(coordinates[1], coordinates[0]);
    for (int i = 1; i < coordinates.size() - 1; i++)
    {
      if (getSlop(coordinates[i + 1], coordinates[i]) != slope)
      {
        return false;
      }
    }

    return true;
  }

  bool checkStraightLine_v2(vector<vector<int>> &coordinates)
  {
    if (coordinates.size() < 3)
      return true;
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    //int slope2;

    //int slope= float((y2-y1)/(x2-x1));
    //cout<<slope<<endl;

    for (int i = 2; i < coordinates.size(); i++)
    {
      int x3 = coordinates[i][0];
      int y3 = coordinates[i][1];

      if ((y2 - y1) * (x3 - x1) != (y3 - y1) * (x2 - x1))
        return false;
    }
    return true;
  }
};