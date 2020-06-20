/*
1299. Replace Elements with Greatest Element on Right Side

Level: Easy

https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side


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

  1 <= arr[i] <= 10^5
*/

class Solution
{
public:
  /*
    Time complexity: O(n)
    Space complexity: O(1)
  */
  vector<int> replaceElements(vector<int> &arr)
  {
    int maxVal = -1;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
      // exchange replaces the value with new_value and returns the old value. 
      maxVal = max(maxVal, exchange(arr[i], maxVal));
    }
    return arr;
  }
};