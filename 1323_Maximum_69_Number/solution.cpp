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
    int maximum69Number (int num) {
      string s = to_string(num);

      for(int i = 0 ; i < s.size(); i ++){
        if(s[i] == '6')
        {
          s[i] = '9';
          break;
        }
      }  

      return stoi(s);
    }
};