/*
396. Rotate Function

Level: Medium

https://leetcode.com/problems/rotate-function
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
    //http://bookshadow.com/weblog/2016/09/11/leetcode-rotate-function/
    //用每一行系数与其上一行做差，差值恰好为sum(A) - size * A[size - x]，其中x为行数
*/

class Solution
{
public:
  int maxRotateFunction(vector<int> &A)
  {
    const int n = A.size();
    int sum = 0;
    int f = 0;
    for (int i = 0; i < n; ++i)
    {
      sum += A[i];
      f += i * A[i];
    }
    int ans = f;
    for (int i = 0; i < n - 1; ++i)
    {
      f = f + sum - n * A[n - i - 1];
      ans = max(ans, f);
    }
    return ans;
  }
};