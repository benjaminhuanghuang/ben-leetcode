/*
172. Factorial Trailing Zeroes

Level: Easy

https://leetcode.com/problems/factorial-trailing-zeroes
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

  Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    /*
    n! = 1*2*3*4... *n
    The number of trailing 0 = the count of 2*5 pair
    https://discuss.leetcode.com/topic/6848/my-explanation-of-the-log-n-solution
 
    */
    int trailingZeroes(int n) {
        int count_five = 0;
        while (n > 0)
        {
            int k = n / 5;
            count_five += k;
            n = k;
        }
        return count_five;
    }
};