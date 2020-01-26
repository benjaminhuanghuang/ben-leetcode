'''
475. Heaters

Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm
all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that
all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum
radius standard of heaters.

Note:
    Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
    Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
    As long as a house is in the heaters' warm radius range, it can be warmed.
    All the heaters follow your radius standard and the warm radius will the same.

Example 1:
    Input: [1,2,3],[2]
    Output: 1
    Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
    Input: [1,2,3,4],[1,4]
    Output: 1
    Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.


http://www.itdadao.com/articles/c15a934233p0.html
two points to house and heater
'''


class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int

        """
        houses.sort()
        heaters.sort()
        len_house = len(houses)
        len_heater = len(heaters)
        min = 0
        j = 0
        for i in range(len_house):
            # find distance between house and nearest heater
            while (j < len_heater - 1 and abs(heaters[j] - houses[i]) >= abs(heaters[j + 1] - houses[i])):
                j += 1

            min = max(min, abs(heaters[j] - houses[i]))
        return min


# [1, 2, 3], [2]
# [1, 2, 3, 4], [1, 4]
houses = [1, 5]
heaters = [2]

s = Solution()

print s.findRadius(houses, heaters)
