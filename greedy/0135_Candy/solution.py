class Solution(object):
    # http://www.cnblogs.com/slurm/p/5366982.html
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        candy = [1 for i in range(n)]
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candy[i] = candy[i - 1] + 1

        for i in range(n - 1, 0, -1):
            if ratings[i] < ratings[i - 1] and candy[i] >= candy[i - 1]:
                candy[i - 1] = candy[i] + 1

        return sum(candy)
