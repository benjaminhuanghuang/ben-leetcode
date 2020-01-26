'''
189. Rotate Array

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.


'''


class Solution(object):
    def rotate_lazy(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        # !! Do not use nums = nums[n - k:] + nums[:n - k]
        nums[:] = nums[n - k:] + nums[:n - k]

    def reverse(self, nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

    # time O(n) space O(1)
    def rotate(self, nums, k):
        if not nums:
            return

        if k <= 0:
            return

        n = len(nums)
        k %= n

        # reverse first part
        self.reverse(nums, 0, n - k - 1)
        # reverse second part
        self.reverse(nums, n - k, n - 1)
        # reverse whole list
        self.reverse(nums, 0, n - 1)

    # time O(kn) space O(1)
    def rotate_3(self, nums, k):
        if not nums:
            return

        if k <= 0:
            return

        n = len(nums)
        k %= n
        t = 0
        while t < k:
            last = nums[-1]
            for i in xrange(n - 1, 0, -1):
                nums[i] = nums[i - 1]
            nums[0] = last
            t += 1


s = Solution()
nums = [1, 2, 3, 4, 5, 6, 7]
s.rotate_3(nums, 3)

print nums
