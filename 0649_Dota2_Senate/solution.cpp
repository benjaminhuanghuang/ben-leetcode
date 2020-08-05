/*
649. Dota2 Senate

Level: Medium

https://leetcode.com/problems/dota2-senate
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
  用两个队列queue，把各自阵营的位置存入不同的队列里面，
  然后进行循环，每次从两个队列各取一个位置出来，看其大小关系，小的那个说明在前面，就可以把后面的那个Ban掉，
  所以我们要把小的那个位置要加回队列里面，但是不能直接加原位置，因为下一轮才能再轮到他来Ban，
  所以我们要加上一个n，再排入队列。
*/

class Solution
{
public:
  string predictPartyVictory(string senate)
  {
    int n = senate.size();
    queue<int> q1, q2;
    for (int i = 0; i < n; ++i)
    {
      (senate[i] == 'R') ? q1.push(i) : q2.push(i);
    }
    while (!q1.empty() && !q2.empty())
    {
      int i = q1.front();
      q1.pop();
      int j = q2.front();
      q2.pop();
      (i < j) ? q1.push(i + n) : q2.push(j + n);
    }
    return (q1.size() > q2.size()) ? "Radiant" : "Dire";
  }
};