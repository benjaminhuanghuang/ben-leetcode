'''
164. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
'''


class Solution(object):
    def maximumGap(self, nums):
        if not nums or len(nums) < 2:
            return 0

        length = len(nums)
        minVal = min(nums)
        maxVal = max(nums)

        bucketSize = max(1, (maxVal - minVal - 1) / (length - 1) + 1)
        bucketNumber = (maxVal - minVal) / bucketSize + 1
        buckets = [None] * bucketNumber
        for i in nums:
            bucketIndex = (i - minVal) / bucketSize
            bucket = buckets[bucketIndex]
            if bucket is None:
                buckets[bucketIndex] = [i, i]  # min an max value in bucket

            else:
                bucket[0] = min(bucket[0], i)
                bucket[1] = max(bucket[1], i)
        ans = 0
        bucketIndex = 0
        while bucketIndex < bucketNumber:
            if buckets[bucketIndex] is None:
                bucketIndex += 1
                continue
            nextBucket = bucketIndex + 1
            while nextBucket < bucketNumber and buckets[nextBucket] is None:
                nextBucket += 1
            if nextBucket < bucketNumber:
                ans = max(ans, buckets[nextBucket][0] - buckets[bucketIndex][1])
            bucketIndex = nextBucket

        return ans

    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums or len(nums) < 2:
            return 0

        gap = 0
        nums = sorted(nums)
        for i in xrange(1, len(nums)):
            gap = max(gap, nums[i] - nums[i - 1])
        return gap


s = Solution()
input = [100, 3, 2, 1]
print s.maximumGap(input)
