'''
349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

'''


def arrays_interseciton(nums1, nums2):
    return set(nums1).intersection(nums2)


# Input:
#   [1,2,2,1]
#   [2]
# Output:
#   [2,2]
# Expected:
#   [2]
def arrays_interseciton_2(nums1, nums2):
    return [x for x in set(nums1) if x in set(nums2)]


def arrays_interseciton_3(nums1, nums2):
    return list(set(nums1) & set(nums2))


b1 = [1, 2, 3, 4, 5, 9, 11, 15]
b2 = [4, 5, 6, 7, 8]

print arrays_interseciton(b1, b2)
