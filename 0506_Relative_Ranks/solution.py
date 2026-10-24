class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sorted_nums = sorted(nums, reverse=True)
        score_dict = {score: idx for idx, score in enumerate(sorted_nums)}
        res = []
        for score in nums:
            if score_dict[score] < 3:
                res.append(['Gold', 'Silver', 'Bronze'][score_dict[score]] + ' Medal')
            else:
                res.append(str(score_dict[score] + 1))
        return res

    def findRelativeRanks_better(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        dmap = {v: k for k, v in enumerate(sorted(nums, reverse=True))}
        return [str(dmap[n] + 1) \
                    if dmap[n] > 2 \
                    else ['Gold', 'Silver', 'Bronze'][dmap[n]] + ' Medal' for n in nums]
