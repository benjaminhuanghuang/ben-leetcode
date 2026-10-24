def has_duplicate(nums):
    return len(nums) > len(set(nums))


nums = [2,2]

print has_duplicate(nums)