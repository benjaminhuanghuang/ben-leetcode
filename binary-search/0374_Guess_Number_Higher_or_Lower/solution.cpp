/*
374. Guess Number Higher or Lower

Level: Easy

https://leetcode.com/problems/guess-number-higher-or-lower
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
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution
{
public:
  int guessNumber(int n)
  {
    int l = 1;
    int r = n;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      int comparison = guess(mid);

      if (comparison < 0) // number is lower
      {
        r = mid - 1;
      }
      else if (comparison > 0) // number is higher
      {
        l = mid + 1;
      }
      else
      {
        return mid;
      }
    }
    return l;
  }
};