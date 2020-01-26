/*
1073. Adding Two Negabinary Numbers

Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

 

Example 1:

Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
 

Note:

1 <= arr1.length <= 1000
1 <= arr2.length <= 1000
arr1 and arr2 have no leading zeros
arr1[i] is 0 or 1
arr2[i] is 0 or 1
*/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
  {
    if (arr1.empty())
      return arr2;

    if (arr2.empty())
      return arr1;

    vector<int> ans;
    int carry = 0;
    int i1 = arr1.size() - 1;
    int i2 = arr2.size() - 1;
    while (i1 >= 0 || i1 >= 0)
    {
      int v1 = i1 >= 0 ? arr1[i1--] : 0;
      int v2 = i2 >= 0 ? arr2[i2--] : 0;
      int sum = v1 + v2 + carry;
      carry = sum / 2;
      ans.insert(ans.begin(), sum % 2);
    }
    if (carry > 0)
      ans.insert(ans.begin(), carry);
    return ans;
  }
};
/*
https://zxi.mytechroad.com/blog/simulation/leetcode-1073-adding-two-negabinary-numbers/
 */
class Solution
{
public:
  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
  {
    int i = arr1.size();
    int j = arr2.size();
    int carry = 0;
    vector<int> ans;
    while (i || j || carry)
    {
      int sum = (i ? arr1[--i] : 0) + (j ? arr2[--j] : 0) + carry;
      ans.push_back(sum & 1);
      carry = -(sum >> 1);
    }
    while (ans.back() == 0 && ans.size() > 1)
      ans.pop_back();
    reverse(begin(ans), end(ans));
    return ans;
  }
};