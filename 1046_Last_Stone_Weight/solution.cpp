/*
1046. Last Stone Weight

https://leetcode.com/problems/last-stone-weight/

*/

#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    //priority_queue默认排序是less，也就说大顶堆, 取值时是最大值。
    priority_queue<int> q;
    for (int s : stones)
      q.push(s);
    while (q.size() > 1)
    {
      int x = q.top();
      q.pop();
      int y = q.top();
      q.pop();
      if (x == y)
        continue;
      q.push(abs(x - y));
    }
    return q.empty() ? 0 : q.top();
  }
};