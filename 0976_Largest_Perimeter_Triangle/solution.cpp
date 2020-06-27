/*
976. Largest Perimeter Triangle

Level: Easy

https://leetcode.com/problems/largest-perimeter-triangle
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-976-largest-perimeter-triangle/
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(rbegin(A), rend(A));
    for (int i = 0; i < A.size() - 2; ++i)
      if (A[i] < A[i + 1] + A[i + 2])
        return A[i] + A[i + 1] + A[i + 2];
    return 0; 
    }
};