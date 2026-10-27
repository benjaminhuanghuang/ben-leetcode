/*
2133. Check if Every Row and Column Contains All Numbers

Easy

https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
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
#include <functional>
#include <bitset>

using namespace std;

class Solution {
 public:
  bool checkValid(vector<vector<int>>& matrix) {
    const int n = matrix.size();

    for (int i = 0; i < n; ++i) {
      bitset<101> row;
      bitset<101> col;
      for (int j = 0; j < n; ++j) {
        row[matrix[i][j]] = true;
        col[matrix[j][i]] = true;
      }
      if (min(row.count(), col.count()) < n)
        return false;
    }

    return true;
  }
};