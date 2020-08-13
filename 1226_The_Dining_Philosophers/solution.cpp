/*
1226. The Dining Philosophers

Level: Medium

https://leetcode.com/problems/the-dining-philosophers/
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  
*/

class DiningPhilosophers
{
public:
  DiningPhilosophers()
  {
  }

  void wantsToEat(int philosopher,
                  function<void()> pickLeftFork,
                  function<void()> pickRightFork,
                  function<void()> eat,
                  function<void()> putLeftFork,
                  function<void()> putRightFork)
  {
  }
};

class DiningPhilosophers
{
private:
  bool arr[5];
  mutex m;
  mutex marr[5];

public:
  DiningPhilosophers()
  {
    for (int i = 0; i < 5; ++i)
    {
      arr[i] = true;
    }
  }

  bool check(int index, int index2)
  {
    m.lock();

    bool ret = arr[index] && arr[index2];
    if (ret)
    {
      arr[index] = false;
      arr[index2] = false;
    }

    m.unlock();
    return ret;
  }

  void wantsToEat(int philosopher,
                  function<void()> pickLeftFork,
                  function<void()> pickRightFork,
                  function<void()> eat,
                  function<void()> putLeftFork,
                  function<void()> putRightFork)
  {

    int index = philosopher;
    int index2 = philosopher + 1;
    if (philosopher + 1 == 5)
    {
      index2 = 0;
    }

    bool canEat = check(index, index2);
    while (canEat == false)
    {
      marr[philosopher].lock();
      canEat = check(index, index2);
    }

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();

    arr[index] = true;
    arr[index2] = true;

    int pre = philosopher - 1;
    if (pre == -1)
    {
      pre = 4;
    }
    marr[pre].unlock();
    marr[philosopher].unlock();
    marr[index2].unlock();
  }
};