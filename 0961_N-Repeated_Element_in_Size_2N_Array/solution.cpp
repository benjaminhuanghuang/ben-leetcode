/*
961. N-Repeated Element in Size 2N Array

Level: Easy

https://leetcode.com/problems/n-repeated-element-in-size-2n-array
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
  https://zxi.mytechroad.com/blog/randomization/leetcode-961-n-repeated-element-in-size-2n-array/
*/

class Solution
{
public:
  int repeatedNTimes(vector<int> &A)
  {
    int i = 0;
    int j = 0;
    while (i == j || A[i] != A[j])
    {
      i = rand() % A.size();
      j = rand() % A.size();
    }
    return A[i];
  }
};