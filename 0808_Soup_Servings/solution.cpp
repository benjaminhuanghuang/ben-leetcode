/*
808. Soup Servings

Level: Medium

https://leetcode.com/problems/soup-servings
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
  
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-808-soup-servings/
*/

class Solution {
public:
  double soupServings(int N) {
    if (N >= 5000) return 1.0;
    return prob(N, N);
  }
private:
  unordered_map<int, unordered_map<int, double>> m_;
  double prob(int A, int B) {
    static int ops[][2] = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    if (A <= 0 && B <= 0) return 0.5;
    if (A <= 0) return 1.0;    
    if (B <= 0) return 0.0;
    if (m_.count(A) && m_[A].count(B)) return m_[A][B];    
    m_[A][B] = 0.0;
    for (int i = 0; i < 4; ++i)
      m_[A][B] += 0.25 * prob(A - ops[i][0], B - ops[i][1]);
    return m_[A][B];
  }
};