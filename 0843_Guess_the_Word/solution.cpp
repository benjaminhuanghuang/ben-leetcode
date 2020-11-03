/*
843. Guess the Word

Level: Hard

https://leetcode.com/problems/guess-the-word
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.cnblogs.com/grandyang/p/11449244.html
*/

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master
{
public:
  int guess(string word);
};

class Solution
{
public:
  void findSecretWord(vector<string> &wordlist, Master &master)
  {
    for (int i = 0, cnt = 0; i < 10 && cnt < 6; ++i)
    {
      string guess = wordlist[rand() % (wordlist.size())];
      cnt = master.guess(guess);   // API call
      vector<string> t;
      for (string &word : wordlist)
      {
        if (match(guess, word) == cnt)
        {
          t.push_back(word);
        }
      }
      wordlist = t;
    }
  }
  int match(string &a, string &b)
  {
    int res = 0, n = a.size();
    for (int i = 0; i < n; ++i)
    {
      if (a[i] == b[i])
        ++res;
    }
    return res;
  }
};