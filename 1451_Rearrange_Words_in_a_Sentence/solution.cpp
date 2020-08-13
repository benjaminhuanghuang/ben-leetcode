/*
1451. Rearrange Words in a Sentence

Level: Medium

https://leetcode.com/problems/rearrange-words-in-a-sentence
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
  https://zxi.mytechroad.com/blog/string/leetcode-1451-rearrange-words-in-a-sentence/
*/

class Solution {
public:
  string arrangeWords(string text) {
    vector<string> words{""};
    for (char c : text) {
      if (c == ' ') 
        words.push_back("");
      else
        words.back() += c;
    }
    
    words[0][0] = tolower(words[0][0]);
    
    stable_sort(begin(words), end(words), [](const auto& w1, const auto& w2){
      return w1.length() < w2.length();
    });
    
    string ans;
    for (const string& word : words) {
      if (!ans.empty()) ans += ' ';
      ans += word;
    }
    ans[0] = toupper(ans[0]);
    return ans;
  }
};