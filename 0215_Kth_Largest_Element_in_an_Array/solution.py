'''
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order,
not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 <= k <= array's length.
'''


class Solution(object):
    def findKthLargest_lazy(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sorted(nums, reverse=True)[k - 1]

    # https://segmentfault.com/a/1190000003704825
    # O(n) time, O(1) Space
    # 1. select nums[0] as pivot
    # 2. tail means the end position of elements are larger than pivot
    # 3. swap pivot with nums[tail]
    # If tail + 1 == k: return pivot. Since (tail) elements larger than pivot, so pivot is (tail + 1)th largest
    # If tail + 1 < k: result is among the window excluding pivot, so cut off nums to nums[:tail](nums[tail] is pivot, kicked out)
    # If tail + 1 > k: result is outside of window, so cut off nums to nums[tail+1:].
    # Quick select
    # Step 0: [3,2,1,5,6,4]
    # Step 1: [3,5,1,2,6,4]
    # Step 2: [3,5,6,2,1,4]
    # ...
    # [3,5,6,4,2,1]
    #
    def findKthLargest(self, nums, k):
        pivot = nums[0]
        tail = 0

        for i in range(1, len(nums)):
            if nums[i] > pivot:
                tail += 1
                nums[tail], nums[i] = nums[i], nums[tail]

        nums[tail], nums[0] = nums[0], nums[tail]

        if tail + 1 == k:
            return pivot
        elif tail + 1 < k:
            return self.findKthLargest(nums[tail + 1:], k - tail - 1)
        else:
            return self.findKthLargest(nums[:tail], k)  # excluding pivot


s = Solution()
print s.findKthLargest([3,2,1,5,6,4], 3)