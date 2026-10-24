'''
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative
order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

'''


def move_zero(nums):
    current = 0
    for index, item in enumerate(nums):
        if nums[index] != 0:
            nums[current] = nums[index]
            current += 1

    for index in xrange(current, len(nums)):    # wrong: current +1
        nums[index] = 0


# naive version
def moveZeroes(nums):
    oldlen = len(nums)
    tmplist = filter(lambda x: x != 0, nums)
    del nums[:]
    for i in range(oldlen):
        if i < len(tmplist):
            nums.append(tmplist[i])
        else:
            nums.append(0)
