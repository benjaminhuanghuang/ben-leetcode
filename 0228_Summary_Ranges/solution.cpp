/*
228. Summary Ranges
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
  两个指针 start, end.  如果nums[end+1] = nums[end]+1, 就移动end指针,
  否则, 插入字符串nums[start]->nums[end].
*/
class Solution
{
public:
  vector<string> summaryRanges(vector<int> &nums)
  {
    vector<string> res;
    if (nums.empty())
      return res;

    int start = 0, end = 0;
    while (end < nums.size())
    {
      if (end + 1 < nums.size() && nums[end + 1] == nums[end] + 1)
      {
        end++;
      }
      else
      {
        if (start == end)
        {
          res.push_back(to_string(nums[start]));
        }
        else
        {
          string str = to_string(nums[start]) + "->" + to_string(nums[end]);
          res.push_back(str);
        }
        ++end;
        start = end;
      }
    }
    return res;
  }
};