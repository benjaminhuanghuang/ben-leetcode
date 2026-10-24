'''
496. Next Greater Element I  #503

You are given two arrays (without duplicates) nums1 and nums2 where nums1's elements are subset of nums2.
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].

Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.

'''

# http://www.cnblogs.com/grandyang/p/6399855.html
class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        for num in findNums:
            next_greater = -1
            for i in range(len(nums)):
                if nums[i] == num:
                    break

            for j in range(i + 1, len(nums)):
                if nums[j] > num:
                    next_greater = nums[j]
                    break

            res.append(next_greater)
        return res

    def nextGreaterElement_better(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        dict = {}
        for idx, num in enumerate(nums):
            dict[num] = idx

        for num in findNums:
            next_greater = -1
            start = dict[num]
            for i in range(start + 1, len(nums)):
                if nums[i] > num:
                    next_greater = nums[i]
                    break

            res.append(next_greater)
        return res


s = Solution()
print s.nextGreaterElement_better([2], [1, 3, 4, 2])
