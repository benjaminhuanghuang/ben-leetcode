/*
433. Minimum Genetic Mutation

Level: Medium

https://leetcode.com/problems/minimum-genetic-mutation
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
  BFS Shortest Path
  Time complexity: O(n^2)

  Space complexity: O(n)
*/

class Solution
{
public:
  int minMutation(string start, string end, vector<string> &bank)
  {
    queue<string> q;
    q.push(start);

    unordered_set<string> visited;
    visited.insert(start);

    int mutations = 0;
    while (!q.empty())
    {
      size_t size = q.size();
      while (size--)
      {
        string curr = std::move(q.front());
        q.pop();
        if (curr == end)
          return mutations;
        for (const string &gene : bank)
        {
          if (visited.count(gene) || !validMutation(curr, gene))
            continue;
          visited.insert(gene);
          q.push(gene);
        }
      }
      ++mutations;
    }
    return -1;
  }

private:
  bool validMutation(const string &s1, const string &s2)
  {
    int count = 0;
    for (int i = 0; i < s1.length(); ++i)
      if (s1[i] != s2[i] && count++)
        return false;
    return true;
  }
};