/*
836. Rectangle Overlap

Level: Easy

https://leetcode.com/problems/rectangle-overlap
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
  bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
  {
    int left_1 = rec1[0];
    int bottom_1 = rec1[1];
    int right_1 = rec1[2];
    int top_1 = rec1[3];

    int left_2 = rec2[0];
    int bottom_2 = rec2[1];
    int right_2 = rec2[2];
    int top_2 = rec2[3];

    return !(top_2 <= bottom_1 ||
             bottom_2 >= top_1 ||
             right_2 <= left_1 ||
             left_2 >= right_1);
  }
};