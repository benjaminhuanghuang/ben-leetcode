/*
1409. Queries on a Permutation With Key

Level: Medium

https://leetcode.com/problems/queries-on-a-permutation-with-key
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
  https://zxi.mytechroad.com/blog/simulation/leetcode-1409-queries-on-a-permutation-with-key/
*/

/*
  Solution1: Simulation + Hashtable

  Use a hashtable to store the location of each key.
  For each query q, use h[q] to get the index of q, for each key, if its current index is less than q, increase their indices by 1. (move right). Set h[q] to 0.

  Time complexity: O(q*m)
  Space complexity: O(m)
*/

class Solution
{
public:
  vector<int> processQueries(vector<int> &queries, int m)
  {
    vector<int> numbers(m);                // p is numbers
    iota(begin(numbers), end(numbers), 1); // fill number 1 to m

    vector<int> ans;
    for (int q : queries)
    {
      for (int i = 0; i < m; i++)
      {
        if (numbers[i] == q)
        {
          for (int j = i; j > 0; j--)
          {
            numbers[j] = numbers[j - 1];
          }
          numbers[0] = q;
          ans.push_back(i);
        }
      }
    }
    return ans;
  }
};

class Solution
{
public:
  vector<int> processQueries(vector<int> &queries, int m)
  {
    vector<int> p(m + 1);
    iota(begin(p), end(p), -1); // // fill number -1 to m

    vector<int> ans;
    for (int q : queries)
    {
      ans.push_back(p[q]);
      for (int i = 1; i <= m; ++i)
        if (p[i] < p[q])
          ++p[i];
      p[q] = 0;
    }
    return ans;
  }
};

class Fenwick {
public:
  explicit Fenwick(int n): vals_(n) {}
  
  // sum(A[1~i])
  int query(int i) const {
    int s = 0;
    while (i > 0) {
      s += vals_[i];
      i -= i & -i;
    }
    return s;
  }
  
  // A[i] += delta
  void update(int i, int delta) {
    while (i < vals_.size()) {
      vals_[i] += delta;
      i += i & -i;
    }
  }
private:
  vector<int> vals_;
};
 
class Solution {
public:
  vector<int> processQueries(vector<int>& queries, int m) {
    Fenwick tree(m * 2  + 1);
    vector<int> pos(m + 1);
    for (int i = 1; i <= m; ++i)     
      tree.update(pos[i] = i + m, 1);
    
    vector<int> ans;
    for (int q : queries) {
      ans.push_back(tree.query(pos[q] - 1));
      tree.update(pos[q], -1); // set to 0.      
      tree.update(pos[q] = m--, 1); // move to the front.
    }
    return ans;
  }
};