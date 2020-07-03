/*
239. Sliding Window Maximum

Level: Hard

https://leetcode.com/problems/sliding-window-maximum
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <multiset>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
*/
class MonotonicQueue
{
public:
  // push element, pop all elements smaller than e
  void push(int e)
  {
    while (!data_.empty() && e > data_.back())
      data_.pop_back();
    data_.push_back(e);
  }
  // pop max element
  void pop()
  {
    data_.pop_front();
  }

  int max() const { 
    return data_.front(); 
  }

private:
  deque<int> data_;
};

class Solution
{
public:
  /*
    Time complexity: O((n – k + 1) * k)  
      (n – k + 1)个window, 从k个element中找最大值，时间复杂度为k
       当k = n/2时，时间复杂度接近 n^2
    Space complexity: O(1)
    */
  vector<int> maxSlidingWindow_bruteforce(vector<int> &nums, int k)
  {
    vector<int> ans;
    for (int i = k - 1; i < nums.size(); ++i)
    {
      ans.push_back(*max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
    }
    return ans;
  }

  /*
    Time complexity: O((n – k + 1) * logk)

    Space complexity: O(k)
  */
  vector<int> maxSlidingWindow_bst(vector<int> &nums, int k)
  {
    vector<int> ans;
    if (nums.empty())
      return ans;
    multiset<int> window(nums.begin(), nums.begin() + k - 1);
    for (int i = k - 1; i < nums.size(); ++i)
    {
      window.insert(nums[i]);
      ans.push_back(*window.rbegin());
      if (i - k + 1 >= 0)
        window.erase(window.equal_range(nums[i - k + 1]).first);
    }
    return ans;
  }

  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    MonotonicQueue q;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i)
    {
      q.push(nums[i]);
      if (i - k + 1 >= 0)
      {
        ans.push_back(q.max());
        if (nums[i - k + 1] == q.max())
          q.pop();
      }
    }
    return ans;
  }
};