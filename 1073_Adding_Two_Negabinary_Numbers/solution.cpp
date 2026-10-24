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