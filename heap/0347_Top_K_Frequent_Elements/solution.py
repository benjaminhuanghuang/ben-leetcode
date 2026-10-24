'''
347. Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 <=k <= number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


http://bookshadow.com/weblog/2016/05/02/leetcode-top-k-frequent-elements/

'''
import collections
import heapq


class Solution(object):
    def topKFrequent_my(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # my_dict = dict()
        # for i in nums:
        #     if i in my_dict:
        #         my_dict[i] +=1
        #     else:
        #         my_dict[i] = 1
        count_dict = collections.Counter(nums)
        count_dict = sorted(count_dict, key=lambda x: count_dict[x], reverse=True)
        res = []
        for i in xrange(0, k):
            # pick up most two largest number in my_dict
            res.append(count_dict[i])

        return res

    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        counts = collections.Counter(nums)
        heap = []
        for key, count in counts.items():
            if len(heap) < k:
                heapq.heappush(heap, (count, key))
            else:
                if heap[0][0] < count:
                    heapq.heappop(heap)
                    heapq.heappush(heap, (count, key))
        return [x[1] for x in heap]

    def topKFrequent_2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # my_dict = dict()
        # for i in nums:
        #     if i in my_dict:
        #         my_dict[i] +=1
        #     else:
        #         my_dict[i] = 1
        my_dict = collections.Counter(nums)

        r_list = list()
        for i in xrange(0, k):
            # pick up most two largest number in my_dict
            temp = max(my_dict, key=lambda i: my_dict[i])
            r_list.append(temp)
            my_dict.pop(temp, None)

        return r_list


s = Solution()

print s.topKFrequent_my([1, 1, 1, 2, 2, 3], 2)
