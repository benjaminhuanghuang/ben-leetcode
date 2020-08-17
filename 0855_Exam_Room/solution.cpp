/*
855. Exam Room

Level: Medium

https://leetcode.com/problems/exam-room
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class ExamRoom
{
public:
  ExamRoom(int N)
  {
    n = N;
  }

  int seat()
  {
    int start = 0, mx = 0, idx = 0;
    for (int i : spots)
    {
      if (start == 0)
      {
        if (mx < i - start)
        {
          mx = i - start;
          idx = 0;
        }
      }
      else
      {
        if (mx < (i - start + 1) / 2)
        {
          mx = (i - start + 1) / 2;
          idx = start + mx - 1;
        }
      }
      start = i + 1;
    }
    if (start > 0 && mx < n - start)
    {
      mx = n - start;
      idx = n - 1;
    }
    spots.insert(idx);
    return idx;
  }

  void leave(int p)
  {
    spots.erase(p);
  }

private:
  int n;
  set<int> spots;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */