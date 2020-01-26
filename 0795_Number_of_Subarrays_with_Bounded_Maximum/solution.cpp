/*
795. Number of Subarrays with Bounded Maximum
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
*/
#include <vector>
#include <unordered_set>

using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/array/leetcode-795-number-of-subarrays-with-bounded-maximum/
问一个数组中有多少个子数组的最大元素值在[L, R]的范围里。
*/
class Solution
{
public:
  int numSubarrayBoundedMax(vector<int> &A, int L, int R)
  {
    int ans = 0;
    int left = -1;
    int right = -1;
    for (int i = 0; i < A.size(); ++i)
    {
      if (A[i] >= L)
        right = i;
      if (A[i] > R)
        left = i;
      ans += (right - left);
    }
    return ans;
  }
};

/*
我们定义[left, right]表示符合条件的合法区间，并且遍历数组A，根据A[right]的大小，可以分为三种情况进行处理：

1）A[right]在[L, R]区间内，所以此时我们拥有从[left, right]...到[right, right]一共(right - left + 1)个合法的区间，所以我们更新res += (right - left + 1)，并且更新count的值（后面会有用）；
2）A[right]小于L，此时虽然A[right]不在[L, R]区间内，但是对于前面的count个合法区间，每个加上A[right]，仍然可以形成合法的区间，所以res += moves；
3）A[right] > R，此时所有包含A[right]的区间都将不再合法，所以我们更新左边界left = right + 1，并更新count = 0。

算法的空间复杂度为O(1)，时间复杂度为O(n)
*/