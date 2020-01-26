/*
4. Median of Two Sorted Arrays [Hard]

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

https://leetcode.com/problems/median-of-two-sorted-arrays/
*/
#include <vector>

using namespace std;
/*
  https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/

  */
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    // Make sure n1 <= n2
    if (n1 > n2)
      return findMedianSortedArrays(nums2, nums1);

    const int k = (n1 + n2 + 1) / 2;

    int l = 0;
    int r = n1;

    while (l < r)
    {
      const int m1 = l + (r - l) / 2;
      const int m2 = k - m1;
      if (nums1[m1] < nums2[m2 - 1])
        l = m1 + 1;
      else
        r = m1;
    }

    const int m1 = l;
    const int m2 = k - l;

    const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                       m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

    if ((n1 + n2) % 2 == 1)
      return c1;

    const int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1],
                       m2 >= n2 ? INT_MAX : nums2[m2]);

    return (c1 + c2) * 0.5;
  }
};
/*
  https://www.youtube.com/watch?v=do7ibYtv5nk&t=339s

  对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1], 若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2;

  Case1: m + n is even, median = (number[total/2] + number[total/2 +1]) /2
  Case2: m + n is odd, median =  number[total/2 +1]

  设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素;
  取A[k / 2] B[k / 2] 比较; 如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法);
  反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的; k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决;
  如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。

*/
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
    return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
  }

private:
  int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
  {
    // Case 1: overstep
    if (i >= nums1.size())
      return nums2[j + k - 1]; // all of nums in nums1 were removed
    if (j >= nums2.size())
      return nums1[i + k - 1];
    // case 2: k =1
    if (k == 1)
      return min(nums1[i], nums2[j]);

    // case 3: 每次砍掉 k／2个数字
    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    // cut number for nums1 or nums2
    if (midVal1 < midVal2)
    {
      return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    }
    else
    {
      return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
  }
};