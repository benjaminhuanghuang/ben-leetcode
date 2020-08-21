/*
  992. Subarrays with K Different Integers
  https://leetcode.com/problems/subarrays-with-k-different-integers/
*/

#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-123/
  https://zxi.mytechroad.com/blog/two-pointers/leetcode-992-subarrays-with-k-different-integers/
  Solution: Two pointers + indirection

    Let f(x) denote the number of subarrays with x or less distinct numbers.
    ans = f(K) – f(K-1)
    It takes O(n) Time and O(n) Space to compute f(x) 
*/
class Solution {
public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    // Returns the number of subarrays with k or less distinct numbers.
    auto subarrys = [&A](int k) {
      vector<int> count(A.size() + 1);
      int ans = 0;
      int i = 0;
      for (int j = 0; j < A.size(); ++j) {
        if (count[A[j]]++ == 0) 
          --k;
        while (k < 0)
          if (--count[A[i++]] == 0) ++k;
        ans += j - i + 1;
      }
      return ans;
    };
    return subarrys(K) - subarrys(K - 1);
  }
};