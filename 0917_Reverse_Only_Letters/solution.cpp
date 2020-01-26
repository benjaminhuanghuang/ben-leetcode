/*
917. Reverse Only Letters
https://leetcode.com/problems/reverse-only-letters/
*/
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  string reverseOnlyLetters(string S)
  {
    if (S.empty())
      return S;

    int l = 0;
    int r = S.size() - 1;
    while (l < r)
    {
      if (isalpha(S[l]) && isalpha(S[r]))
      {
        swap(S[l++], S[r--]);
      }
      else
      {
        if (!isalpha(S[l]))
          ++l;
        if (!isalpha(S[r]))
          --r;
      }
    }
    return S;
  }
};