/*
966. Vowel Spellchecker

https://leetcode.com/problems/vowel-spellchecker/

给了一个单词字典，给出了一堆要查询的词，要返回查询结果。查询的功能如下：

    如果字典里有现在的单词，就直接返回；
    如果不满足1，那么判断能不能更改要查询单词的某些大小写使得结果在字典中，如果字典里多个满足条件的，就返回第一个；
    如果不满足2，那么判断能不能替换要查询单词的元音字符成其他的字符使得结果在字典中，如果字典里多个满足条件的，就返回第一个；
    如果不满足4，返回查询的结果是空字符串。
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-966-vowel-spellchecker/
Solution: HashTable

Using 3 hashtables: original words, lower cases, lower cases with vowels replaced to “*”

Time complexity: O(|W|+|Q|)
Space complexity: O(|W|)
*/
class Solution
{
public:
  vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
  {
    vector<string> ans;
    unordered_map<string, string> m_org;
    unordered_map<string, string> m_low;
    unordered_map<string, string> m_vow;
    for (const string &w : wordlist)
    {
      // Original word
      m_org[w] = w;
      // Case-insensitive
      string l = toLower(w);
      if (!m_low.count(l))
        m_low[l] = w;
      // Vowel-insensitive
      string o = replaceVowels(l);
      if (!m_vow.count(o))
        m_vow[o] = w;
    }

    for (const string &q : queries)
    {
      if (m_org.count(q))
      {
        ans.push_back(q);
        continue;
      }
      string l = toLower(q);
      if (m_low.count(l))
      {
        ans.push_back(m_low[l]);
        continue;
      }

      string o = replaceVowels(l);
      if (m_vow.count(o))
      {
        ans.push_back(m_vow[o]);
        continue;
      }
      ans.push_back("");
    }
    return ans;
  }

private:
  string toLower(const string &s)
  {
    string l(s);
    std::transform(begin(s), end(s), begin(l), ::tolower);
    return l;
  }

  string replaceVowels(const string &s)
  {
    string o(s);
    for (char &c : o)
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        c = '*';
    return o;
  }
};