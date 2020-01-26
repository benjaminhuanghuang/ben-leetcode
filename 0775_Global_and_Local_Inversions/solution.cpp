/*
775. Global and Local Inversions

https://leetcode.com/problems/global-and-local-inversions/
*/

#include <vector>
#include <numeric>

using namespace std;

/*
Brute Force (TLE)

Time complexity: O(n^2)

Space complexity: O(1)
*/
class Solution
{
public:
  bool isIdealPermutation(vector<int> &A)
  {
    const int n = A.size();
    int local = 0;
    for (int i = 0; i < n - 1; ++i)
      if (A[i] > A[i + 1])
        ++local;
    int global = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (A[i] > A[j] && ++global > local)
          return false;
    return global == local;
  }
};

/*
https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-775-global-and-local-inversions/
Solution2: MergeSort

Time complexity: O(nlogn)

Space complexity: O(n)
*/

class Solution
{
public:
  bool isIdealPermutation(vector<int> &A)
  {
    const int n = A.size();
    int local = 0;
    for (int i = 0; i < n - 1; ++i)
      if (A[i] > A[i + 1])
        ++local;
    tmp = vector<int>(n);
    int global = mergeSort(A, 0, n - 1);
    return global == local;
  }

private:
  vector<int> tmp;
  int mergeSort(vector<int> &A, int l, int r)
  {
    if (l >= r)
      return 0;
    const int len = r - l + 1;
    int m = (r - l) / 2 + l;
    int inv = mergeSort(A, l, m) + mergeSort(A, m + 1, r);

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
      if (A[i] <= A[j])
      {
        tmp[k++] = A[i++];
      }
      else
      {
        tmp[k++] = A[j++];
        inv += m - i + 1;
      }
    }

    while (i <= m)
      tmp[k++] = A[i++];
    while (j <= r)
      tmp[k++] = A[j++];

    std::copy(tmp.begin(), tmp.begin() + len, A.begin() + l);

    return inv;
  }
};