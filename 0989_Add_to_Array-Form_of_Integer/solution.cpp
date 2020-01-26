/*
989. Add to Array-Form of Integer
https://leetcode.com/problems/add-to-array-form-of-integer/
*/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> addToArrayForm(vector<int> &A, int K)
  {
    vector<int> ans;
    int i = A.size() - 1;
    int carry = 0;
    while (i >= 0 && K > 0)
    {
      int sum = A[i] + K % 10;
      carry = sum / 10;
      ans.insert(ans.begin(), sum % 10);
      i--;
      K = K / 10;
    }
    if (i > 0)
    {
    }
    if (K > 0)
    {
    }
    if (carry > 0)
    {
    }
    return ans;
  }
};

/*
https://zxi.mytechroad.com/blog/simulation/leetcode-989-add-to-array-form-of-integer/
*/
class Solution
{
public:
  vector<int> addToArrayForm(vector<int> &A, int K)
  {
    vector<int> ans;
    ans.reserve(A.size() + 1);   // save time than inster()
    for (int i = A.size() - 1; i >= 0 || K > 0; --i)
    {
      K += (i >= 0 ? A[i] : 0);
      ans.push_back(K % 10);
      K /= 10;
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
};


class Solution_Slow
{
public:
  vector<int> addToArrayForm(vector<int> &A, int K)
  {
    vector<int> ans;
    int i = A.size() - 1;
    while (i >= 0 || K > 0)
    {
      K += (i >= 0 ? A[i] : 0);
      ans.insert(ans.begin(), K % 10);
      i--;
      K = K / 10;
    }
    return ans;
  }
};