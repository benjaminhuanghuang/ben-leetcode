/*
127. Word Ladder
https://leetcode.com/problems/word-ladder/
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

/*
http://zxi.mytechroad.com/blog/searching/127-word-ladder/ 

最短路径类型的题目一般用BFS

Time Complexity: O(n*26^l), l = len(word), n=|wordList| 单词个数

Space Complexity: O(n)
*/

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
      return 0;

    queue<string> q;  // BFS
    q.push(beginWord);

    int l = beginWord.length();
    int step = 0;

    while (!q.empty())
    {
      ++step;
      for (int size = q.size(); size > 0; size--)
      {
        string w = q.front();
        q.pop();
        for (int i = 0; i < l; i++)
        {
          char ch = w[i];
          for (int j = 'a'; j <= 'z'; j++)
          {
            w[i] = j;
            // Found the solution !!
            if (w == endWord)
              return step + 1;
            // Not in dict, skip it
            if (!dict.count(w))
              continue;
            // Remove new word from dict
            dict.erase(w);
            // Add new word into queue
            q.push(w);
          }
          w[i] = ch;
        }
      }
    }
    return 0;
  }
};

/*
Solution 2: Bidirectional BFS
Time Complexity: O(n*26^l/2), l = len(word), n=|wordList| 单词个数

Space Complexity: O(n)
*/
class Solution_Bidirectional
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
      return 0;

    int l = beginWord.length();

    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};

    int step = 0;

    while (!q1.empty() && !q2.empty())
    {
      ++step;

      // Always expend the smaller queue first
      if (q1.size() > q2.size())
        std::swap(q1, q2);

      unordered_set<string> q;

      for (string w : q1)
      {
        for (int i = 0; i < l; i++)
        {
          char ch = w[i];
          for (int j = 'a'; j <= 'z'; j++)
          {
            w[i] = j;
            if (q2.count(w))
              return step + 1;
            if (!dict.count(w))
              continue;
            dict.erase(w);
            q.insert(w);
          }
          w[i] = ch;
        }
      }

      std::swap(q, q1);
    }

    return 0;
  }
};