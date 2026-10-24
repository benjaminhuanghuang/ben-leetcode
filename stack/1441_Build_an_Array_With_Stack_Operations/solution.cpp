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
  vector<string> buildArray(vector<int> &target, int n)
  {
    vector<string> arr;
    int i = 0;
    int num = 1;
    while (num <= n)
    {
      while (num < target[i])
      {
        arr.push_back("Push");
        arr.push_back("Pop");
        num++;
      }
      //
      arr.push_back("Push");
      i++;
      num++;
    }
    return arr;
  }
};