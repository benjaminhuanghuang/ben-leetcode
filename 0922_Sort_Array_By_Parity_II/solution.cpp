/*
922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/
*/
#include <vector>
#include <algorithm>

using namespace std;

/*
Brute Force
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution
{
public:
  vector<int> sortArrayByParityII(vector<int> &A)
  {
    if (A.empty())
      return {};
    vector<int> evens;
    vector<int> odds;
    for (int a : A)
      if (a % 2 == 0)
        evens.push_back(a);
      else
        odds.push_back(a);
    auto it1 = begin(evens);
    auto it2 = begin(odds);
    for (int i = 0; i < A.size(); ++i)
    {
      A[i] = *it1++;
      swap(it1, it2);
    }
    return A;
  }
};