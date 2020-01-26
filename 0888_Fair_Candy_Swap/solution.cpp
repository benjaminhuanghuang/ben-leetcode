/*
888. Fair Candy Swap

https://leetcode.com/problems/fair-candy-swap/
*/

#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;
/*
交换A,B两个数组中的一个数字，使得两个数组的和相等。要返回的结果是个要交换的两个数字，分别来自A,B。
*/
class Solution
{
public:
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
  {
    int sum_a = accumulate(begin(A), end(A), 0);
    int sum_b = accumulate(begin(B), end(B), 0);
    unordered_set<int> s(begin(B), end(B));
    int diff = (sum_b - sum_a) / 2;
    for (int a : A)
      if (s.count(a + diff))
        return {a, a + diff};
    return {};
  }
};

/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-888-fair-candy-swap/
*/
class Solution_Faster {
public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {    
    int sum_a = accumulate(begin(A), end(A), 0);
    int sum_b = 0;
    unordered_set<int> s;
    // Faster
    for (int b : B) {
      sum_b += b;
      s.insert(b);
    }
    int diff = (sum_b - sum_a) / 2;
    for (int a : A)
      if (s.count(a + diff)) return {a, a + diff};
    return {};
  }
};