/*
1089. Duplicate Zeros
https://leetcode.com/problems/duplicate-zeros/
 */
#include <vector>

using namespace std;
/*
Failed when input is
[0,0,0,0,0,0,0]
*/
class Solution_Error
{
public:
  void duplicateZeros(vector<int> &arr)
  {
    int i = 0;
    while (i < arr.size())
    {
      if (arr[i] == 0 && i != arr.size() - 1)
      {
        int back_i = arr.size() - 1;
        while (back_i >= i + 2)
        {
          arr[back_i] = arr[i - 1];
          back_i--;
        }
        arr[i + 1] = 0;
        i += 2;
      }
      else
      {
        i++;
      }
    }
  }
};

class Solution
{
public:
  void duplicateZeros(vector<int> &arr)
  {
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
      if (arr[i] == 0)
      {
        for (int j = len - 1; j >= i + 1; j--)
        {
          arr[j] = arr[j - 1];
        }
        i = i + 1;
      }
    }
    return;
  }
};

class Solution_Faster
{
public:
  void duplicateZeros(vector<int> &arr)
  {
    int n = arr.size();
    int j = n + count(arr.begin(), arr.end(), 0);
    for (int i = n - 1; i >= 0; --i)
    {
      if (--j < n)
        arr[j] = arr[i];
      if (arr[i] == 0 && --j < n)
        arr[j] = 0;
    }
  }
};