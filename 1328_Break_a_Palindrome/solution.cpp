/*
1328. Break a Palindrome

Level: Medium

https://leetcode.com/problems/break-a-palindrome
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
  1.從左到右先判斷字母有無非a的字元，有則以a取代

  2.如果沒有，則以b取代由右到左第一個出現的a
*/

class Solution
{
public:
  string breakPalindrome(string palindrome)
  {
    if (palindrome.length() == 1)
      return "";
    bool change = false;
    for (int i = 0; i < palindrome.length() / 2; i++)
    {
      if (palindrome[i] != 'a')
      {
        palindrome[i] = 'a';
        change = true;
        break;
      }
    }
    if (change)
    {
      return palindrome;
    }
    else
    {
      palindrome[palindrome.length() - 1] = 'b';
      return palindrome;
    }
  }
};