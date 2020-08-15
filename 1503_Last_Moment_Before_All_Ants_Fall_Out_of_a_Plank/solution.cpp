/*
1503. Last Moment Before All Ants Fall Out of a Plank

Level: Medium

https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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
  int getLastMoment(int n, vector<int> &left, vector<int> &right)
  {
    // left中最右边的
    const int t1 = left.empty() ? 0 : *max_element(cbegin(left), cend(left));
    // right中最左边的
    const int t2 = right.empty() ? 0 : n - *min_element(cbegin(right), cend(right));
    return max(t1, t2);
  }
};