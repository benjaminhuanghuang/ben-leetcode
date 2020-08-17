/*
1054. Distant Barcodes

Level: Medium

https://leetcode.com/problems/distant-barcodes
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
  reorder, 大小相邻的数不再相邻
  Solution: 

  Sort the element by their frequency in descending order. 
  Fill the most frequent element first in even positions, 
  if reach the end of the array, start from position 1 then 3, 5, …

*/

class Solution
{
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes)
  {
    const int n = barcodes.size();
    vector<int> f(10001);
    for (int v : barcodes)
      ++f[v];
    sort(begin(barcodes), end(barcodes), [&](const int a, const int b) {
      return f[a] == f[b] ? a > b : f[a] > f[b];
    });

    vector<int> ans(n);
    int pos = 0;
    
    for (int v : barcodes)
    {
      ans[pos] = v;
      if ((pos += 2) >= n)
        pos = 1; // 最多只能填充两遍，
    }
    return ans;
  }
};