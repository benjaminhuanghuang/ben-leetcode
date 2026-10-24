/*
565. Array Nesting

https://leetcode.com/problems/array-nesting/
*/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int arrayNesting(vector<int> &nums)
  {
    int len = nums.size();
    if (len == 1)
    {
      return 1;
    }

    vector<bool> visited(len);

    int res = 0;

    for (int i = 0; i < len; i++)
    {
      int k = i;
      int count = 0;
      while (!visited[k])
      {
        count++;
        visited[i] = !visited[k];
        k = nums[k];
      }
      res = max(res, count);
    }
    return res;
  }
};