/*
290. Word Pattern

Level: Easy

https://leetcode.com/problems/word-pattern
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  bool wordPattern(string pattern, string str)
  {
    // spit the string
    vector<string> words;
    stringstream ss(str);
    string word;
    while (getline(ss, word, ' '))
    {
      words.push_back(word);
    }

    // check length
    if (words.size() != pattern.length())
    {
      return false;
    }

    //
    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;

    for (int i = 0; i < pattern.size(); i++)
    {
      if (!charToWord.count(pattern[i]))
      {
        charToWord[pattern[i]] = words[i];
      }
      else
      {
        if (charToWord[pattern[i]] != words[i])
          return false;
      }

      if (!wordToChar.count(words[i]))
      {
        wordToChar[words[i]] = pattern[i];
      }
      else
      {
        if (wordToChar[words[i]] != pattern[i])
          return false;
      }
    }

    return true;
  }
};