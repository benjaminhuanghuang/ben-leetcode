/*
219. Contains Duplicate II

https://leetcode.com/problems/contains-duplicate-ii/s
*/
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Flag 
https://www.laioffer.com/en/videos/2018-06-06-219-contains-duplicate-2/
*/

/*
  Time complexity O(N*K)
  Space complexity O(1)
*/
class Solution_Bruteforce
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    if (nums.size() == 0 || k <= 0)
      return false;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = i + 1; j - i <= k && j < nums.size(); ++j)
      {
        if (nums[i] == nums[j])
          return true;
      }
    }
    return false;
  }
};

/*
  hash map  value:index
  Time complexity O(N)
  Space complexity O(N)
*/
class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (m.count(nums[i]))
      {
        int pre = m[nums[i]];
        if (i - pre <= k)
          return true;
      }
      m[nums[i]] = i;
    }
    return false;
  }
};


/*
  Sliding window
  Time complexity O(N)
  Space complexity O(K)
*/
class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (s.count(nums[i]))
      {
        return true;
      }
      s.insert(nums[i]);
      if(i >=k)
      {
        s.erase(nums[i-k]);
      }
    }
    return false;
  }
};