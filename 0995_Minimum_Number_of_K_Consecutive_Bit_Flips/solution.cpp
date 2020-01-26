/*
995. Minimum Number of K Consecutive Bit Flips

https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

using namespace std;
/*
https://zxi.mytechroad.com/blog/greedy/leetcode-995-minimum-number-of-k-consecutive-bit-flips/
*/
class Solution {
public:
  int minKBitFlips(vector<int>& A, int K) {
    vector<int> flipped(A.size());
    int ans = 0;    
    int flip = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (i >= K) flip ^= flipped[i - K];
      if ((A[i] ^ flip) == 0) {
        if (i + K > A.size()) return -1;
        ++ans;
        flip ^= 1;
        flipped[i] = 1;
      }
    }    
    return ans;
  }
};