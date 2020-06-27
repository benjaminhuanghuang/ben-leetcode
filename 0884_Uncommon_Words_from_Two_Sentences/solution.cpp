/*
884. Uncommon Words from Two Sentences

Level: Easy

https://leetcode.com/problems/uncommon-words-from-two-sentences
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
  vector<string> uncommonFromSentences(string A, string B)
  {
    vector<string> ans;
    unordered_map<string, int> counter;

    stringstream ssB(B);
    string word;
    while (ssB >> word)
    {
      counter[word]++;
    }
    stringstream ssA(A);
    while (ssA >> word)
    {
      counter[word]++;
    }

    for (auto kv : counter)
    {
      if (kv.second <= 1)
      {
        ans.push_back(kv.first);
      }
    }
    return ans;
  }
};