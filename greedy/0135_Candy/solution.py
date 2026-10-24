'''
135. Candy

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?


'''


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
