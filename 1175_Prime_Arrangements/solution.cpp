/*
1175. Prime Arrangements

Level: Easy

https://leetcode.com/problems/prime-arrangements
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
  Count the number of primes in range [1, n], assuming there are p primes and n – p non-primes, 
  we can permute each group separately.
  ans = p! * (n – p)!

  Time complexity: O(nsqrt(n))
  Space complexity: O(1)
*/

class Solution
{
public:
  int numPrimeArrangements(int n)
  {
    const int kMod = 1e9 + 7;
    int p = 0;
    for (int i = 1; i <= n; ++i)
      p += isPrime(i);
    long ans = 1;
    for (int i = 1; i <= p; ++i)
      ans = (ans * i) % kMod;
    for (int i = 1; i <= n - p; ++i)
      ans = (ans * i) % kMod;
    return ans;
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