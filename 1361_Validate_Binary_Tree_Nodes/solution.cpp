/*
1361. Validate Binary Tree Nodes

Level: Medium

https://leetcode.com/problems/validate-binary-tree-nodes
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
  Time complexity: O(n)
  Space complexity: O(n)  
*/

class Solution
{
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
  {
    vector<int> inDegree(n, 0);
    vector<int> outDegree(n, 0);
    if (n == 1)
      return true;

    for (int i = 0; i < n; ++i)
    {
      if (leftChild[i] != -1)
      {
        inDegree[leftChild[i]]++;
        outDegree[i]++;
      }
      if (rightChild[i] != -1)
      {
        inDegree[rightChild[i]]++;
        outDegree[i]++;
      }
      if (inDegree[i] > 1)
        return false;
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
      if (inDegree[i] == 0)
        ++count;
      if (outDegree[i] == 0 && inDegree[i] == 0)
        return false;
    }
    return count == 1;
  }
};