/*
4. Median of Two Sorted Arrays

https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

/*
  https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/

  数数共有几个数，加 1，再除以 2

  Binary Search!!
  Time complexity: O(log(min(n1,n2)))
  Space complexity: O(1)      
  */
function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const n1 = nums1.length;
  const n2 = nums2.length;
  // Make sure n1 <= n2
  if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

  const k = Math.floor((n1 + n2 + 1) / 2);

  let l = 0;
  let r = n1;

  while (l < r) {
    const m1 = Math.floor(l + (r - l) / 2);
    const m2 = k - m1;
    if (nums1[m1] < nums2[m2 - 1]) l = m1 + 1;
    else r = m1;
  }

  const m1 = l;
  const m2 = k - l;

  const c1 = Math.max(
    m1 <= 0 ? Number.MIN_SAFE_INTEGER : nums1[m1 - 1],
    m2 <= 0 ? Number.MIN_SAFE_INTEGER : nums2[m2 - 1]
  );

  if ((n1 + n2) % 2 === 1) return c1;

  const c2 = Math.min(
    m1 >= n1 ? Number.MAX_SAFE_INTEGER : nums1[m1],
    m2 >= n2 ? Number.MAX_SAFE_INTEGER : nums2[m2]
  );

  return (c1 + c2) / 2;
}

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
