/*
  1018. Binary Prefix Divisible By 5  [Easy]

  https://leetcode.com/problems/binary-prefix-divisible-by-5/
*/
#include <vector>

using namespace std;
class Solution
{
public:
  vector<bool> prefixesDivBy5(vector<int> &A)
  {
    int num = 0;
    vector<bool> ans(A.size());
    for (int i = 0; i < A.size(); ++i)
    {
      num = ((num << 1) | A[i]) % 5;
      ans[i] = num == 0;
    }
    return ans;
  }
};

class Solution_Overflow
{
public:
  vector<bool> prefixesDivBy5(vector<int> &A)
  {
    vector<bool> ans;
    int cur = 0;
    for (int a : A)
    {
      cur = (cur << 1) + a;   //Overflow!!!
      ans.push_back(cur % 5 == 0);
    }
    return ans;
  }
};

class Solution
{
public:
  vector<bool> prefixesDivBy5(vector<int> &A)
  {
    vector<bool> ans;
    int cur = 0;
    for (int a : A)
    {
      cur = ((cur << 1) + a) % 5; 
      ans.push_back(!cur);
    }
    return ans;
  }
};