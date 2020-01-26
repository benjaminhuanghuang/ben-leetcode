/*
628. Maximum Product of Three Numbers
https://leetcode.com/problems/maximum-product-of-three-numbers/

Given an integer array, find three numbers whose product is maximum and output the maximum product.

*/
#include <vector>
#include <queue>

using namespace std;

/*
https://zxi.mytechroad.com/blog/math/leetcode-628-maximum-product-of-three-numbers/
*/
class Solution_Fastest
{
public:
  int maximumProduct(vector<int> &nums)
  {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (const int num : nums)
    {
      if (num > max1)
      {
        max3 = max2;
        max2 = max1;
        max1 = num;
      }
      else if (num > max2)
      {
        max3 = max2;
        max2 = num;
      }
      else if (num > max3)
      {
        max3 = num;
      }

      if (num < min1)
      {
        min2 = min1;
        min1 = num;
      }
      else if (num < min2)
      {
        min2 = num;
      }
    }

    return max(max1 * max2 * max3, max1 * min1 * min2);
  }
};

/*
Time complexity: O(nlogn)

Space complexity: O(1)
*/
class Solution
{
public:
  int maximumProduct(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.rbegin(), nums.rend());
    return max(nums[0] * nums[1] * nums[2], nums[0] * nums[n - 1] * nums[n - 2]);
  }
};

/*
Solution 3: Two Heaps (Priority Queues)
Time complexity: O(nlog3)
Space complexity: O(2 + 3)
*/
class Solution
{
public:
  int maximumProduct(vector<int> &nums)
  {
    priority_queue<int, vector<int>, less<int>> min_q; // max_heap
    // Compare it returns true if its first argument comes before its second argument
    priority_queue<int, vector<int>, greater<int>> max_q; // min_heap

    for (int num : nums)
    {
      max_q.push(num);
      if (max_q.size() > 3)
        max_q.pop();
      min_q.push(num);
      if (min_q.size() > 2)
        min_q.pop();
    }

    int max3 = max_q.top();
    max_q.pop();
    int max2 = max_q.top();
    max_q.pop();
    int max1 = max_q.top();
    max_q.pop();

    int min2 = min_q.top();
    min_q.pop();
    int min1 = min_q.top();
    min_q.pop();

    return max(max1 * max2 * max3, max1 * min1 * min2);
  }
};