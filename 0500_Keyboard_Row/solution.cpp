/*
500. Keyboard Row

Level: Easy

https://leetcode.com/problems/keyboard-row
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
private:
  bool canInput(string word)
  {
    vector<string> rows = {
        "qwertyuiopQWERTYUIOP",
        "asdfghjklASDFGHJKL",
        "zxcvbnmZXCVBNM"};

    int row = 0;

    for (int i = 0; i < rows.size(); i++)
    {
      if (find(rows[i].begin(), rows[i].end(), word[0]) != rows[i].end())
      {
        row = i;
        break;
      }
    }

    for (char c : word)
    {
      if (rows[row].find(c) == std::string::npos)
      {
        return false;
      }
    }

    return true;
  }

public:
  vector<string> findWords(vector<string> &words)
  {
    vector<string> wordList;
    for (string word : words)
    {
      if (canInput(word))
      {
        wordList.push_back(word);
      }
    }

    return wordList;
  }
};