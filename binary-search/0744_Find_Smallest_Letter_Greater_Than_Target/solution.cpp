/*
744. Find Smallest Letter Greater Than Target

Level: Easy

https://leetcode.com/problems/find-smallest-letter-greater-than-target
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  Note: Given a list of sorted characters letters
*/

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int left = 0;
    int right = letters.size();
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (letters[mid] <= target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }

    return letters[left % letters.size()];
  }
};