/*
1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

Level: Easy

https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
*/
#include <vector>
#include <string>
#include <sstream> // stringstream, getline

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  C++没有自带的切割字符串的方法，可以用stringstream实现分割，O(N)的复杂度.
*/

class Solution
{
public:
  vector<string> splitSentence(const string &text)
  {
    string tmp;
    vector<string> words;
    stringstream ss(text);
    while (getline(ss, tmp, ' '))
    {
      words.push_back(tmp);
    }
    return words;
  }

  int isPrefixOfWord(string sentence, string searchWord)
  {
    auto words = splitSentence(sentence);
    for (int i = 0; i < words.size(); ++i)
    {
      if (words[i].find(searchWord) == 0)
        return i + 1;
    }
    return -1;
  }
};