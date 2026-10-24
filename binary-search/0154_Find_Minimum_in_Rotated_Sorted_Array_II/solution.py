class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 0
        high = len(nums) - 1
        while (low < high):
            if(nums[low] < nums[high]):
                return nums[low]
            mid = low + (high - low) / 2
            if nums[mid] < nums[high]:
                high = mid
            elif (nums[mid] > nums[low]):
                low = mid + 1
            else:
                low += 1
        return nums[low]


nums = [1, 1, 3]

s = Solution()
print s.findMin(nums)
