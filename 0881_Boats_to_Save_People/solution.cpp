/*
881. Boats to Save People

Level: Medium

https://leetcode.com/problems/boats-to-save-people
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
  Solution: two point
  https://www.youtube.com/watch?v=AqpOFr47jQo
*/
class Solution
{
public:
  int numRescueBoats(vector<int> &people, int limit)
  {
    sort(people.begin(), people.end());

    int i =0, j = people.size()-1;
    int res = 0;
    int temp = limit - people[0];

    while(i < j)
    {
      if (people[j] > temp)
      {
        res ++;
        j--;
      }
      else
      {
        res ++;
        j--;
        i++;
        temp = limit - people[i];
      } 
    }
    if(i ==j){
      res ++;
    }
    return res;
  }
};

/*
  Solution: 
  https://www.youtube.com/watch?v=yX5zRzTbeJc
  每艘船最多2个人，最少一个人
*/
class Solution
{
public:
  int numRescueBoats(vector<int> &people, int limit)
  {
    vector<int> p(limit + 1, 0);
    for (int w : people)
      p[w]++;

    int count = 0;
    int x = limit;
    int y = 1;

    while (x > 0)
    {
      while (x > 0 && p[x] == 0)
        x--;
      if (x == 0)
        break;
      count++;
      p[x]--;

      while (y + x <= limit && p[y] == 0)
        y++;
      if (y + x <= limit && p[y] > 0)
        p[y]--;
    }

    return count;
  }
};