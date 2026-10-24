/*
75. Sort Colors

https://leetcode.com/problems/sort-colors/

*/
#include <vector>

using namespace std;

/*
  Solution : Two pointers
  Time complexity: O(n)
  Space complexity: O(1)
*/
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    const int n = nums.size();
    int l = 0;      // last 0
    int r = n - 1;  // first 2
    for (int i = 0; i < n; ++i)
    {
      if (nums[i] == 0)
      {
        swap(nums[i], nums[l++]);
      }
      else if (nums[i] == 2 && i < r)
      {
        swap(nums[i--], nums[r--]);
      }
    }
  }
};

/*
https://www.youtube.com/watch?v=yTwW8WiGrKw&ab_channel=%E6%9D%A5Offer-LaiOffer
三个挡板，
*/
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    const int n = nums.size();
    int l = 0;      // last 0
    int r = n - 1;  // first 2
    int i = 0;      // curr index
    while (i <=r)   //  counter example : [1, 0] , when i = 0 
    {
      if (nums[i] == 0)
      {
        swap(nums[i++], nums[l++]);
      }
      else if(nums[i] == 1){
        i++;
      }
      else
      {
        swap(nums[i], nums[r--]);
      }
    }
  }
};