/*
726. Number of Atoms

Level: Hard

https://leetcode.com/problems/number-of-atoms
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
  Solution: 

  https://www.youtube.com/watch?v=6nQ2jfs7a7I
*/

class Solution
{
public:
  string countOfAtoms(const string &formula)
  {
    int i = 0;
    string ans;
    for (const auto &kv : countOfAtoms(formula, i))
    {
      ans += kv.first;
      if (kv.second > 1)
        ans += std::to_string(kv.second);
    }
    return ans;
  }

private:
  map<string, int> countOfAtoms(const string &formula, int &i)
  {
    map<string, int> counts;
    while (i != formula.length())
    {
      if (formula[i] == '(')
      {
        const auto &tmp_counts = countOfAtoms(formula, ++i);
        const int count = getCount(formula, i);
        for (const auto &kv : tmp_counts)
          counts[kv.first] += kv.second * count;
      }
      else if (formula[i] == ')')
      {
        ++i;
        return counts;
      }
      else
      {
        const string &name = getName(formula, i);
        counts[name] += getCount(formula, i);
      }
    }
    return counts;
  }

  string getName(const string &formula, int &i)
  {
    string name;
    while (isalpha(formula[i]) && (name.empty() || islower(formula[i])))
      name += formula[i++];
    return name;
  }

  int getCount(const string &formula, int &i)
  {
    string count_str;
    while (isdigit(formula[i]))
      count_str += formula[i++];
    return count_str.empty() ? 1 : std::stoi(count_str);
  }
};