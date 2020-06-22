/*
204. Count Primes

Level: Easy

https://leetcode.com/problems/count-primes
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  // https://miafish.wordpress.com/2015/08/05/leetcode-ojc-count-primes/
  int CountPrimes(int n)
  {
    if (n < 1)
      return 0;
    bool isNotPrime[n + 1];
    fill_n(isNotPrime, n + 1, false);
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    for (int i = 2; i < n + 1; i++)
    {
      // loop though 2 to n, for each 1, times 2, 3..n would not be prime.
      if (isNotPrime[i])
        continue;
      // if i is prime
      int times = i + i;
      while (times < n)
      {
        isNotPrime[times] = true;
        times += i;
      }
    }
    // remove 0 and 1
    return count(isNotPrime, isNotPrime + n, false);
  }

  int countPrimes_TLM(int n)
  {
    int count = 0;
    for (int i = 2; i < n; n++)
    {
      if (isPrime(i))
        count++;
    }
    return count;
  }

private:
  bool isPrime(int x)
  {
    if (x < 2)
      return false;
    if (x == 2)
      return true;
    for (int i = 2; i <= sqrt(x); ++i)
      if (x % i == 0)
        return false;
    return true;
  }
};