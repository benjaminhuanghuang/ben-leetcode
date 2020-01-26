/*
131. Palindrome Partitioning

https://leetcode.com/problems/palindrome-partitioning/
*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    vector<string> curr;
    dfs(s, 0, curr, ans);
    return ans;
  }

private:
  bool isPalindrome(string s)
  {
    for (int i = 0; i < s.length() / 2; i++)
      if (s[i] != s[s.length() - i - 1])
        return false;
    return true;
  }

  void dfs(string &s, int start, vector<string> &curr, vector<vector<string>> &ans)
  {
    if (start == s.length())
    {
      ans.push_back(curr);
      return;
    }
    for (int i = start; i < s.length(); i++)
    {
      if (isPalindrome(s.substr(start, i - start + 1)))
      {
        curr.push_back(s.substr(start, i - start + 1));
        dfs(s, i + 1, curr, ans);
        curr.pop_back();
      }
    }
  }
};