/*
1053. Previous Permutation With One Swap
https://leetcode.com/problems/previous-permutation-with-one-swap/
*/
#include <vector>
using namespace std;
/*
要找出字典序小于自己的最大值，方法如下：从后往前遍历A，对于任意一个A[i]，在[i+1,A.length]区间内找出比自己小的最大值，
如果能找到这样的值，则这两个元素交换，交换之后的A即为字典序小于自己的最大值。
怎么找出[i+1,A.length]区间内找出比自己小的最大值？可以把区间内所有的值存入有序的数组中，通过二分查找即可。
*/

/*
https://leetcode.com/problems/previous-permutation-with-one-swap/discuss/299215/JavaC%2B%2BPython-Leetcode-didn't-Match-Lee's-Code
*/
class Solution
{
public:
  vector<int> prevPermOpt1(vector<int> &A)
  {
    int n = A.size(), left = n - 2, right = n - 1;
    while (left >= 0 && A[left] <= A[left + 1])
      left--;
    if (left < 0)
      return A;
    while (A[left] <= A[right])
      right--;
    while (A[right - 1] == A[right])
      right--;
    swap(A[left], A[right]);
    return A;
  }
};