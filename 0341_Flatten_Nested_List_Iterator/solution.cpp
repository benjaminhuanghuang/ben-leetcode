/*
341. Flatten Nested List Iterator

Level: Medium

https://leetcode.com/problems/flatten-nested-list-iterator
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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger
{
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
  NestedIterator(vector<NestedInteger> &nestedList)
  {
    // 倒序插入
    for (int i = nestedList.size() - 1; i >= 0; --i)
    {
      s.push(nestedList[i]);
    }
  }

  int next()
  {
    NestedInteger t = s.top();
    s.pop();
    return t.getInteger();
  }

  bool hasNext()
  {
    while (!s.empty())
    {
      NestedInteger t = s.top();
      if (t.isInteger())
        return true;
      s.pop();
      for (int i = t.getList().size() - 1; i >= 0; --i)
      {
        s.push(t.getList()[i]);
      }
    }
    return false;
  }

private:
  stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


/*
构造函数的时候就利用迭代的方法把这个嵌套链表全部压平展开
*/
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        make_queue(nestedList);
    }

    int next() {
        int t = q.front(); q.pop();
        return t; 
    }

    bool hasNext() {
        return !q.empty();
    }
    
private:
    queue<int> q;
    void make_queue(const vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            if (a.isInteger()) q.push(a.getInteger());
            else make_queue(a.getList());
        }
    }
};