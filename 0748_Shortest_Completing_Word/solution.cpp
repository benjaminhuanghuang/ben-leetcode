/*
748. Shortest Completing Word

Level: Easy

https://leetcode.com/problems/shortest-completing-word
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
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words)
  {
    vector<int> counter(26, 0);
    for (int i = 0; i < licensePlate.size(); i++)
    {
      if (isalpha(licensePlate[i]))
      {
        counter[tolower(licensePlate[i]) - 'a']++;
      }
    }

    int minLen = INT_MAX;
    string minWord;
    for (auto word : words)
    {
      vector<int> wordCounter(26, 0);
      for (char c : word)
      {
        wordCounter[c - 'a']++;
      }

      bool match = true;
      for (int i = 0; i < 26; i++)
      {
        if (counter[i] > wordCounter[i])
        {
          match = false;
          break;
        }
      }
      if (match)
      {
        if (minLen > word.length())
        {
          minWord = word;
          minLen = word.length();
        }
      }
    }
    return minWord;
  }
};