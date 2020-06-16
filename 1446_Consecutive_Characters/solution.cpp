/*
1446. Consecutive Characters

Level: Easy

https://leetcode.com/problems/consecutive-characters
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
    int maxPower(string s) {
      int length = 0;
      int maxLength = 0;
      char current = '\0';
      for(char c : s){
        if(current == '\0' || current != c){
          current = c;
          length = 1;
        }
        else
        {
          length++;
        }
        if (length > maxLength){
          maxLength = length;
        }
      }
      return maxLength;
    }
};