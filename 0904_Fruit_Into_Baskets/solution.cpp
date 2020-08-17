/*
904. Fruit Into Baskets

Level: Medium

https://leetcode.com/problems/fruit-into-baskets
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;
/*
  https://www.cnblogs.com/grandyang/p/11129845.html
  
  其实就是最多有两个不同字符的最长子串的长度，跟之前那道 [Longest Substring with At Most Two Distinct Characters]
*/

class Solution
{
public:
  int totalFruit(vector<int> &tree)
  {
    int res = 0, start = 0, n = tree.size();
    unordered_map<int, int> fruitCnt;
    for (int i = 0; i < n; ++i)
    {
      ++fruitCnt[tree[i]];
      while (fruitCnt.size() > 2)
      {
        if (--fruitCnt[tree[start]] == 0)
        {
          fruitCnt.erase(tree[start]);
        }
        ++start;
      }
      res = max(res, i - start + 1);
    }
    return res;
  }
};

/*
  Solution: 
  https://www.youtube.com/watch?v=wy5nQ75WBJI
*/

class Solution
{
public:
  int totalFruit(vector<int> &tree)
  {
  }
};

/*
  https://zxi.mytechroad.com/blog/hashtable/leetcode-904-fruit-into-baskets/

*/
class Solution
{
public:
  int totalFruit(vector<int> &tree)
  {
    map<int, int> idx; // {fruit -> last_index}
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < tree.size(); ++i)
    {
      int f = tree[i];
      if (!idx.count(f))
      {
        if (idx.size() == 2)
        {
          auto it1 = begin(idx);
          auto it2 = next(it1);
          if (it1->second > it2->second)
            swap(it1, it2);
          cur = i - it1->second - 1;
          idx.erase(it1);
        }
      }
      idx[f] = i;
      ans = max(++cur, ans);
    }
    return ans;
  }
};