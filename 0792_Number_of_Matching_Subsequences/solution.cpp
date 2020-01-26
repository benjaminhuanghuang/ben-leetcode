/*
792. Number of Matching Subsequences
https://leetcode.com/problems/number-of-matching-subsequences/
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
https://zxi.mytechroad.com/blog/string/leetcode-792-number-of-matching-subsequences/
Time complexity: O((S + L) * W)

C++ w/o cache TLE

Space complexity: O(1)

C++ w/ cache 155 ms

Space complexity: O(W * L)

*/
class Solution
{
public:
  int numMatchingSubseq(const string &S, vector<string> &words)
  {
    int ans = 0;
    unordered_map<string, bool> m;
    for (const string &word : words)
    {
      auto it = m.find(word);
      if (it == m.end())
      {
        bool match = isMatch(word, S);
        ans += m[word] = match;
      }
      else
      {
        ans += it->second;
      }
    }
    return ans;
  }

private:
  bool isMatch(const string &word, const string &S)
  {
    int start = 0;
    for (const char c : word)
    {
      bool found = false;
      for (int i = start; i < S.length(); ++i)
        if (S[i] == c)
        {
          found = true;
          start = i + 1;
          break;
        }
      if (!found)
        return false;
    }
    return true;
  }
};

/*
https://zxi.mytechroad.com/blog/string/leetcode-792-number-of-matching-subsequences/
Indexing+ Binary Search

Time complexity: O(S + W * L * log(S))

Space complexity: O(S)

S: length of S

W: number of words

L: length of a word
*/
class Solution
{
public:
  int numMatchingSubseq(const string &S, vector<string> &words)
  {
    vector<vector<int>> pos(128);
    for (int i = 0; i < S.length(); ++i)
      pos[S[i]].push_back(i);
    int ans = 0;
    for (const string &word : words)
      ans += isMatch(word, pos);
    return ans;
  }

private:
  unordered_map<string, bool> m_;
  bool isMatch(const string &word, const vector<vector<int>> &pos)
  {
    if (m_.count(word))
      return m_[word];
    int last_index = -1;
    for (const char c : word)
    {
      const vector<int> &p = pos[c];
      const auto it = std::lower_bound(p.begin(), p.end(), last_index + 1);
      if (it == p.end())
        return m_[word] = false;
      last_index = *it;
    }
    return m_[word] = true;
  }
};
