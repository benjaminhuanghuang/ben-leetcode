/*
349. Intersection of Two Arrays [Easy]

https://leetcode.com/problems/intersection-of-two-arrays/
*/

#include <unordered_set>
#include <vector>

using namespace std;

/*
Sort + Two pointers
*/
class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> intersection;
    int i = 0, j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] < nums2[j])
        ++i;
      else if (nums1[i] > nums2[j])
        ++j;
      else
      {
        // find intersection
        if (intersection.empty() || intersection.back() != nums1[i])
        {
          intersection.push_back(nums1[i]);
        }
        ++i;
        ++j;
      }
    }
    return intersection;
  }
};

/*
Hashset
*/
class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    // put nums1 into hashset
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> ans;
    for (int num : nums2)
    {
      if (!m.count(num))
        continue;
      ans.push_back(num);
      m.erase(num);
    }
    return ans;
  }
};