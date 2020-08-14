/*
869. Reordered Power of 2

Level: Medium

https://leetcode.com/problems/reordered-power-of-2
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
*/

class Solution {
public:
  bool reorderedPowerOf2(int N) {    
    auto m = countMap(N);
    for (int i = 0; i < 31; ++i)
      if (m == countMap(1 << i)) return true;
    return false;
  }
private:
  map<int, int> countMap(int n) {
    map<int, int> m;
    while (n) {
      ++m[n % 10];
      n /= 10;
    }
    return m;
  }
};