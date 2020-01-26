/*
819. Most Common Word

https://leetcode.com/problems/most-common-word/
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string mostCommonWord(string paragraph, vector<string> &banned)
  {
    unordered_set<string> b(banned.begin(), banned.end());
    unordered_map<string, int> counts;
    // the seperators in the paragraph
    const string pattern = "!?',;. ";
    int mostTimes = 0;
    string ans;
    const int n = paragraph.size();
    string word;
    // go through each char in the paragraph
    for (int i = 0; i <= n; ++i)
    {
      if (i == n || pattern.find(paragraph[i]) != string::npos)
      {
        if (++counts[word] > mostTimes && !b.count(word) && word.size() > 0)
        {
          mostTimes = counts[word];
          ans = word;
        }
        word.clear();
      }
      else
      {
        word += tolower(paragraph[i]);
      }
    }
    return ans;
  }
};