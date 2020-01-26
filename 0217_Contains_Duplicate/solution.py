'''
217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.
'''


def has_duplicate(nums):
    return len(nums) > len(set(nums))


nums = [2,2]

print has_duplicate(nums)