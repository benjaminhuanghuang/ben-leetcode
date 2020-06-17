/*
1408. String Matching in an Array

Level: Easy

https://leetcode.com/problems/string-matching-in-an-array
*/
#include <vector>
#include <string>
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
  vector<string> stringMatching_v1(vector<string> &words)
  {
    vector<string> ans;
    for (auto word : words)
    {
      int count = 0;
      for (auto otherWord : words)
      {
        if (otherWord.find(word) != string::npos)
          count++;
      }
      if (count >= 2)
        ans.push_back(word);
    }
    return ans;
  }
  vector<string> stringMatching(vector<string> &words)
  {
    // sort from short to longer
    sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });

    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
      for (int j = i + 1; j < words.size(); j++)
      {
        if (words[j].find(words[i]) != string::npos)
        {
          ans.push_back(words[i]);
          break;
        }
      }
    }
    return ans;
  }
};