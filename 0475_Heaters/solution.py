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
