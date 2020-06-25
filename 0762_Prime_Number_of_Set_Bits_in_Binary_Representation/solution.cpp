/*
762. Prime Number of Set Bits in Binary Representation

Level: Easy

https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation
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
  int countPrimeSetBits(int L, int R)
  {
    int ans = 0;
    for (int i = L; i <= R; i++)
    {
      if (isPrime(bits(i)))
      {
        ans++;
      }
    }
    return ans;
  }

private:
  bool isPrime(int n)
  {
    if (n <= 1)
      return false;
    if (n == 2)
      return true;
    for (int i = 2; i <= (int)sqrt(n); ++i)
      if (n % i == 0)
        return false;
    return true;
  }

  int bits(int n)
  {
    int s = 0;
    while (n != 0)
    {
      s += n & 1;
      n >>= 1;
    }
    return s;
  }
};