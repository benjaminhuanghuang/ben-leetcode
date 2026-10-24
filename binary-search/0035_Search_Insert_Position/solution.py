class Solution(object):
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left + 1 < right:
            mid = left + (right - left) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid
            else:
                left = mid

        if nums[left] >= target:
            return left
        if nums[right] >= target:
            return right
        return right + 1


s = Solution()
print s.searchInsert([1, 3], 2)

print s.searchInsert([1, 3], 3)
