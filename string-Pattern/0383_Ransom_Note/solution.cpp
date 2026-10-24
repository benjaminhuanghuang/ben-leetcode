/*
383. Ransom Note
https://leetcode.com/problems/ransom-note/
*/

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    vector<int> counts(128, 0);
    for (const char c : magazine)
      ++counts[c];
    for (const char c : ransomNote)
      if (--counts[c] < 0)
        return false;
    return true;
  }
};