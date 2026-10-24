/*

401. Binary Watch

https://leetcode.com/problems/binary-watch/

*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
https://zxi.mytechroad.com/blog/bit/leetcode-401-binary-watch/

Time complexity: O(11*59*n)
*/
class Solution
{
public:
  vector<string> readBinaryWatch(int num)
  {
    vector<string> ans;
    for (int i = 0; i <= num; ++i)
      for (int h : nums(i, 12))
        for (int m : nums(num - i, 60))
          ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return ans;
  }

private:
  // Return numbers in [0,r) that has b 1s in their binary format.
  vector<int> nums(int b, int r)
  {
    vector<int> ans;
    for (int n = 0; n < r; ++n)
    {
      //count set bits in an integer.
      if (__builtin_popcount(n) == b)
        ans.push_back(n);
    }
    return ans;
  }
};

class Solution2
{
public:
  vector<string> readBinaryWatch(int num)
  {
    vector<string> ans;
    for (int h = 0; h < 12; h++)
    {

      for (int m = 0; m < 60; m++)
      {

        // Number of set bits in hour portion and in minute
        // part has to be equal to num.
        if (__builtin_popcount(h) + __builtin_popcount(m) == num)
        {
          ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        }
      }
    }
    return ans;
  }
};