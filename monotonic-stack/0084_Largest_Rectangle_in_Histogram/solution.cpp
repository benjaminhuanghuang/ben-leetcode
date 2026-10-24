/*
84. Largest Rectangle in Histogram

https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <vector>
#include <stack>

using namespace std;

/*
  log(N^2)
*/
class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int res = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
      if (i + 1 < heights.size() && heights[i] <= heights[i + 1])
      {
        continue;
      }
      int minH = heights[i];
      for (int j = i; j >= 0; --j)
      {
        minH = min(minH, heights[j]);
        int area = minH * (i - j + 1);
        res = max(res, area);
      }
    }
    return res;
  }
};

/*
    https://www.youtube.com/watch?v=TH9UaZ6JGcA

    单调栈的维护是 O(n) 级的时间复杂度，因为所有元素只会进入栈一次，并且出栈后再也不会进栈了。

    https://www.cnblogs.com/grandyang/p/4322653.html
     */

class Solution2
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int res = 0;
    stack<int> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
      {
        int cur = st.top();
        st.pop();
        res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
      }
      st.push(i);
    }
    return res;
  }
};
