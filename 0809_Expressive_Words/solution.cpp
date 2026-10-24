#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
*/
class Solution
{
public:
  int expressiveWords(string S, vector<string> &words)
  {
    int res = 0, lenS = S.size();
    for (string word : words)
    {
      int i = 0, j = 0; // S[i], word[j]
      for (; i < lenS; ++i)
      {
        if (j < word.size() && S[i] == word[j])
          ++j;
        else if (i > 0 && S[i] == S[i - 1] && i + 1 < lenS && S[i] == S[i + 1])
          ++i;
        else if (!(i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2]))
          break;
      }
      if (i == lenS && j == word.size())
        ++res;
    }
    return res;
  }
};