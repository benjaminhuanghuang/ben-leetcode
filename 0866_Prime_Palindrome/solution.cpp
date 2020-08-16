/*
866. Prime Palindrome

Level: Medium

https://leetcode.com/problems/prime-palindrome
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
  https://www.cnblogs.com/grandyang/p/10714003.html

  除了11之外，所有长度为偶数的回文数都不是质数

*/

class Solution
{
  int primePalindrome(int N)
  {
    if (N >= 8 && N <= 11)
      return 11;
    for (int i = 1; i < 1e5; ++i)
    {
      string s = to_string(i), t(s.rbegin(), s.rend());
      int x = stoi(s + t.substr(1));
      if (x >= N && isPrime(x))
        return x;
    }
    return -1;
  }
  bool isPrime(int num)
  {
    if (num < 2 || num % 2 == 0)
      return num == 2;
    int limit = sqrt(num);
    for (int i = 3; i <= limit; ++i)
    {
      if (num % i == 0)
        return false;
    }
    return true;
  }
};