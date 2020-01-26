/*
890. Find and Replace Pattern

https://leetcode.com/problems/find-and-replace-pattern/
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
Two hashtables to handle the mapping
https://www.cnblogs.com/grandyang/p/10920449.html
*/
class Solution
{
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern)
  {
    vector<string> res;
    for (string word : words)
    {
      unordered_map<char, char> w2p, p2w;
      int i = 0, n = word.size();
      for (; i < n; ++i)
      {
        //word -> pattern
        if (w2p.count(word[i]) && w2p[word[i]] != pattern[i])  // NO word->pattern
          break;
        w2p[word[i]] = pattern[i];

        // pattern->word
        if (p2w.count(pattern[i]) && p2w[pattern[i]] != word[i])
          break;
        p2w[pattern[i]] = word[i];
      }
      if (i == n)
        res.push_back(word);
    }
    return res;
  }
};

/*
https://zxi.mytechroad.com/blog/string/leetcode-890-find-and-replace-pattern/
*/
class Solution
{
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern)
  {
    vector<string> ans;
    for (const string &w : words)
      if (match(w, pattern))
        ans.push_back(w);
    return ans;
  }

private:
  bool match(const string &w, const string &p)
  {
    vector<int> last_pos_w(128, INT_MIN); // last pos of x in w
    vector<int> last_pos_p(128, INT_MIN); // last pos of x in p
    for (int i = 0; i < w.size(); ++i)
      if (last_pos_w[w[i]] != last_pos_p[p[i]])
      {
        return false;
      }
      else
      {
        last_pos_w[w[i]] = last_pos_p[p[i]] = i;
      }
    return true;
  }
};