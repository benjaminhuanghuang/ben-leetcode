/*
461. Hamming Distance

Level: Easy

https://leetcode.com/problems/hamming-distance
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
  int hammingDistance(int x, int y)
  {
    int distance = 0;
    int z = x ^ y;
    for (int i = 0; i < 32; i++)
    {
      distance += (z >> i) & 1;
    }
    return distance;
  }
};