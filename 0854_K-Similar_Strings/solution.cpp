/*
854. K-Similar Strings [Hard]

https://leetcode.com/problems/k-similar-strings/
*/
#include <string>
#include <climits>
#include <vector>

using namespace std;

/*
https://blog.csdn.net/AzureoSky/article/details/82888509
*/

class Solution
{
public:
  int kSimilarity(string A, string B)
  {
    int len = A.size(), pos = 0, k = INT_MAX;
    vector<int> swapIdxes;
    for (int i = 0; i < len; ++i)
    {
      if (A.at(i) == B.at(i))
        continue;
      bool best = false, fit = false;
      pos = i;
      for (int j = i + 1; j < len; ++j)
      {
        if (A.at(j) != B.at(i) || A.at(j) == B.at(j))
          continue;
        fit = true;
        if (A.at(i) == B.at(j))
        {
          swapIdxes.clear();
          swapIdxes.push_back(j);
          best = true;
          break;
        }
        swapIdxes.push_back(j);
      }
      if (best || fit)
        break;
    }
    for (int i : swapIdxes)
    {
      swap(A[pos], A[i]);
      k = min(k, 1 + kSimilarity(A.substr(pos + 1), B.substr(pos + 1)));
      swap(A[pos], A[i]);
    }
    if (swapIdxes.empty())
      return 0;
    return k;
  }
};