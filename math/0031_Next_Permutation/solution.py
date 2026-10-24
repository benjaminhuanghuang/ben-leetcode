'''
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1

'''


class Solution(object):
    # https://www.hrwhisper.me/leetcode-permutations/
    #
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        j, k = len(nums) - 2, len(nums) - 1
        # from right to left, find out the "first" number it is less than the adjacent number at right side
        while j >= 0:
            if nums[j] < nums[j + 1]:
                break
            j -= 1

        # if all number arranges descending, sort (ascending order) and return
        if j < 0:
            nums.sort()
            return
        # The right section of the numbers are in descending order
        # find smallest number (bigger than nums[j])in the right section of the numbers
        while k > j:
            if nums[k] > nums[j]:
                break
            k -= 1
        nums[j], nums[k] = nums[k], nums[j]
        # reverse the right section
        nums[:] = nums[:j + 1] + nums[:j:-1]


s = Solution()

input = [1, 3, 0, 6, 5]
s.nextPermutation(input)
print input

input = [1, 2, 3, 4]
s.nextPermutation(input)
print input

input = [3, 2, 1]
s.nextPermutation(input)
print input
