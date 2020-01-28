/*
1332. Remove Palindromic Subsequences

Level: Easy

https://leetcode.com/problems/remove-palindromic-subsequences
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

class Solution {
public:
    int removePalindromeSub(string s) {
      if (s.empty()) return 0;
      if (s == string(rbegin(s), rend(s))) return 1;
      return 2;  
    }
};