/*
880. Decoded String at Index

Level: Medium

https://leetcode.com/problems/decoded-string-at-index
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
*/
class Solution
{
public:
  string decodeAtIndex(string S, int K)
  {
    long i = 0, cnt = 0;
    for (; cnt < K; ++i)
    {
      cnt = isdigit(S[i]) ? cnt * (S[i] - '0') : (cnt + 1);
    }
    while (i--)
    {
      if (isdigit(S[i]))
      {
        cnt /= (S[i] - '0');
        K %= cnt;
      }
      else
      {
        if (K % cnt == 0)
          return string(1, S[i]);
        --cnt;
      }
    }
    return "";
  }
};

class Solution
{
public:
  string decodeAtIndex(string S, int K)
  {
    long cnt = 0;
    for (int i = 0; i < S.size(); ++i)
    {
      if (isalpha(S[i]))
      {
        if (++cnt == K)
          return string(1, S[i]);
      }
      else
      {
        if (cnt * (S[i] - '0') >= K)
          return decodeAtIndex(S.substr(0, i), (K - 1) % cnt + 1);
        cnt *= (S[i] - '0');
      }
    }
    return "";
  }
};