'''
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


Hints:
    Generalize this question to "Kth element in 2 sorted arrays".
    Median : If there is an odd number of numbers, the middle one is picked.
             If there are an even number of numbers, the median is the mean of the two middle values.
'''


class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        count = len(nums1) + len(nums2)

        if count % 2 == 1:
            # if count = 3, get n[1]
            return self.kth(nums1, nums2, count / 2)
        else:
            # if count = 4, get (n[1] + n[2]) /2
            return float(self.kth(nums1, nums2, count / 2) + self.kth(nums1, nums2, count / 2 - 1)) / 2

    def kth(self, nums1, nums2, k):
        if not nums1:
            return nums2[k]
        if not nums2:
            return nums1[k]

        mid1 = len(nums1) / 2
        mid2 = len(nums2) / 2

        if mid1 + mid2 < k:   # make mid bigger
            if nums1[mid1] > nums2[mid2]:  # extend nums2
                return self.kth(nums1, nums2[mid2 + 1:], k - mid2 - 1)
            else: # extend nums1
                return self.kth(nums1[mid1 + 1:], nums2, k - mid1 - 1)
        else:  # mid1 + mid2 >= k, make mid smaller
            if nums1[mid1] > nums2[mid2]:
                return self.kth(nums1[:mid1], nums2, k)
            else:
                return self.kth(nums1, nums2[:mid2], k)
