'''
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.

'''


# naive
# sorting takes time of nlog(n)
def majority_element(nums):
    if len(nums) == 1:
        return nums[0]

    sorted_nums = sorted(nums)
    count = 1
    prev = sorted_nums[0]
    for i in xrange(1, len(sorted_nums)):
        if sorted_nums[i] == prev:
            count += 1
            if count > len(sorted_nums) / 2:
                return sorted_nums[i]
        else:
            count = 1
            prev = sorted_nums[i]

    return None


# Since the majority always take more than a half space, the middle element is guaranteed to be the majority.
def majority_element2(nums):
    if len(nums) == 1:
        return nums[0]

    sorted_nums = sorted(nums)
    return sorted_nums[len(sorted_nums) / 2];


# linear time. I think it is incorrect!!!
# Test case [1,1,1,2,2,2,3] return 2 !
def majority_element3(nums):
    count = 0

    for i in xrange(1, len(nums)):
        if count == 0:
            result = nums[i]
            count = 1
        elif result == nums[i]:
            count += 1
        else:
            count -= 1

    return result


nums = [1, 1, 1, 2, 2, 2, 3]

print  majority_element(nums)
print  majority_element3(nums)
