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
