/*
231. Power of Two

Level: Easy

https://leetcode.com/problems/power-of-two

- 326. Power of Three     # n % 3
- 342. Power of Four

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

class Solution
{
public:
  /*
    // The power of 2 only have one "1" ant most left bit
    */
  bool isPowerOfTwo(int n)
  {
    int countOfOne = 0;
    while (n > 0)
    {
      countOfOne += n & 1;
      n >>= 1;
    }
    return countOfOne == 1;
  }

  // The power of 2 only have one "1" ant most left bit
  // if minus 1 from it, all of bits in the result will be 1
  bool IsPowerOfTwo_2(int n)
  {
    return (n > 0) && ((n & (n - 1)) == 0);
  }
};