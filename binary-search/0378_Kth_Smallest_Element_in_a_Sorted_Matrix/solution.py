'''
378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order,
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Reference
https://www.hrwhisper.me/leetcode-kth-smallest-element-sorted-matrix/
'''


class Solution(object):
    def kthSmallest_1(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        lo, hi = matrix[0][0], matrix[-1][-1]
        while lo <= hi:
            mid = lo + (hi - lo) >> 1
            temp = sum([self.binary_search(y, mid) for y in matrix])
            if temp >= k:
                hi = mid - 1
            else:
                lo = mid + 1
        return lo

    def binary_search(self, nums, x):
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) >> 1
            if nums[mid] <= x:
                low = mid + 1
            else:
                high = mid
        return low

    def kthSmallest_2(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        low, high = matrix[0][0], matrix[-1][-1]
        n = len(matrix)
        while low < high:
            mid = low + ((high - low) >> 1)
            temp = self.search_lower_than_mid(matrix, n, mid)
            if temp < k:
                low = mid + 1
            else:
                high = mid
        return low

    def search_lower_than_mid(self, matrix, n, x):
        i, j = n - 1, 0
        cnt = 0
        while i >= 0 and j < n:
            if matrix[i][j] <= x:
                j += 1
                cnt += i + 1
            else:
                i -= 1
        return cnt


matrix = [
    [1, 5, 9],
    [10, 11, 13],
    [12, 13, 15]
]

s = Solution()
print s.kthSmallest_1(matrix, 8)
