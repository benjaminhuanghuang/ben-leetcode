/*
387. First Unique Character in a String

https://leetcode.com/problems/first-unique-character-in-a-string/
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    vector<int> count(26);
    for (int i = 0; i < s.size(); i++)
      count[s[i] - 'a']++;
    for (int i = 0; i < s.size(); i++)
      if (count[s[i] - 'a'] == 1)
        return i;
    return -1;
  }
};