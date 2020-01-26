/*
916. Word Subsets
https://leetcode.com/problems/word-subsets/

给定字符串数组A和B，如果字符串b中每个字符的出现次数都<=该字符在a中的出现次数，则称b是a的子集。
如果对于B中的每个字符串b，b都是a的子集，则称a为“universal”。
问A中有多少个字符串是“universal”的。
*/

#include <vector>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/string/leetcode-916-word-subsets/

Solution: Hashtable

Find the max requirement for each letter from B.

Time complexity: O(|A|+|B|)
Space complexity: O(26)
*/

class Solution
{
public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B)
  {
    vector<int> req(26);
    for (const string &b : B)
    {
      // get occurrence of each charactors in the words of B
      vector<int> cur(getCount(b));
      for (int i = 0; i < 26; ++i)
        req[i] = max(req[i], cur[i]);
    }

    vector<string> ans;
    for (const string &a : A)
    {
      vector<int> cur(getCount(a));
      bool universal = true;
      for (int i = 0; i < 26; ++i)
        if (cur[i] < req[i])
        {
          universal = false;
          break;
        }
      if (universal)
        ans.push_back(a);
    }
    return ans;
  }

private:
  vector<int> getCount(const string &a)
  {
    vector<int> count(26);
    for (char c : a)
      ++count[c - 'a'];
    return count;
  }
};