/*
861. Score After Flipping Matrix

Level: Medium

https://leetcode.com/problems/score-after-flipping-matrix
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
  由于数字是由二进制表示的，那么最高位的权重要大于其他位总和的，比如 1000 就要大于 0111 的，所以当最高位是0的时候，无论如何都是需要翻转当前行的
  对于 mxn 的数组来说，每行的二进制数共有n位，最高位是1的话，就是 1<<(n-1)，那么共有m行，所以至少能将 m*(1<<(n-1)) 这么大的值收入囊中，
  因此对于列
  
  若还想增大数字之和，就只能看各列是否还能翻转了，而且是从次高位列开始看，因为最高位列必须保证都是1。
  
  由于每一行的翻转情况已经确定了，那么如何才能确定其他位到底是0还是1呢，
  此时就要看它跟最高位是否相同了，
  若相同的话，不管最高位初始时是0还是1，最终都要变成1，那么当前位一定最终也会变成1，
  而一旦跟最高位相反，那么最后一定会是0。
  
  我们翻转当前列的条件肯定是希望翻转之后1的个数要更多一些，这样值才能增加，所以就要统计每列当前的1的个数，若小于0的个数，
  才进行翻转，然后乘以该列的值，对于第j列，其值为 1<<(n-1-j)

*/

class Solution
{
public:
  int matrixScore(vector<vector<int>> &A)
  {
    int rows = A.size(), cols = A[0].size(), res = (1 << (cols - 1)) * rows;

    for (int j = 1; j < cols; ++j)
    {
      int cnt = 0;   // how many bits are same as the first bit of current row: A[i][0]
      for (int i = 0; i < rows; ++i)
      {
        cnt += (A[i][j] == A[i][0]);
      }
      res += max(cnt, rows - cnt) * (1 << (cols - 1 - j));
    }
    return res;
  }
};