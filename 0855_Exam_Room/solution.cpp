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

https://www.youtube.com/watch?v=-dGB1j3Pk18
*/

class ExamRoom
{
private:
  vector<int> seats;
  int start;
  int end;

public:
  ExamRoom(int N)
  {
    end = N - 1;
    start = 0;
  }

  int seat()
  {
    // first time, seats is empty
    if (seats.size() == 0)
    {
      seats.push_back(start);
      return start;
    }

    int max = 0;
    int pick = -1;
    int index = -1;
    if (seats[0] != 0)
    {
      pick = 0;
      max = seats[0] - 0;
      index = 0;
    }

    int l = 0, r = 0;
    for (int i = 0; i < seats.size(); i++)
    {
      if (i == 0)
      {
        l = seats[0];
        continue;
      }
      else
        l = r;
      r = seats[i];
      int mid = (l + r) >> 1;
      int dt = mid - l;
      if (dt > max)
      {
        max = dt;
        pick = mid;
        index = i;
      }
    }
    if (seats[seats.size() - 1] < end)
    {
      l = seats[seats.size() - 1];
      r = end;
      int dt = r - l;
      if (dt > max)
      {
        max = dt;
        pick = r;
        index = seats.size();
      }
    }
    seats.insert(seats.begin()+ index, pick);
    return pick;
  }

  void leave(int p)
  {
    for (int i = 0; i < seats.size(); i++)
    {
      if (seats[i] == p)
      {
        seats.erase(seats.begin()+i);
        return;
      }
    }
  }
};

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
      if (start == 0) // first on is 0
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