/*
1566. Detect Pattern of Length M Repeated K or More Times

Level: Easy

https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times
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
    对于每个位置，如果 arr(i)== arr(i+m)，则计数器 counter 加 1。否则，计数器清 0。
    如果计数器达到了 m*(k−1)，则找到了一个符合要求的模式。
*/

class Solution
{
public:
  bool containsPattern(vector<int> &arr, int m, int k)
  {
    int n = arr.size();
    int counter = 0;

    for (int i = 0; i < n - m; i++)
    {
      if (arr[i] == arr[i + m])
      {
        counter++;
      }
      else
      {
        counter = 0;
      }

      if (counter == m * (k - 1))
      {
        return true;
      }
    }

    return false;
  }
};