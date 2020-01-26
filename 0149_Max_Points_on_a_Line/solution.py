'''
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

'''

from fractions import Fraction


class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        length = len(points)
        if length < 3:
            return length

        res = 0
        for point in points:
            slope_dict = {'inf': 0}
            samePoints = 0

            for otherpoint in points:
                if point.x == otherpoint.x and point.y == otherpoint.y:
                    samePoints += 1
                elif point.x == otherpoint.x and point.y != otherpoint.y:
                    slope_dict['inf'] += 1
                elif point.x != otherpoint.x:
                    # slope = float(otherpoint.y - point.y) / (otherpoint.x - point.x) can not pass [94911151, 94911150]
                    #slope = Fraction((otherpoint.y - point.y), (otherpoint.x - point.x))  # Time Limit Exceeded
                    slope = str(Fraction((otherpoint.y - point.y), (otherpoint.x - point.x)))
                    if slope not in slope_dict:
                        slope_dict[slope] = 1
                    else:
                        slope_dict[slope] += 1
            res = max(res, max(slope_dict.values()) + samePoints)
        return res


s = Solution()
print s.maxPoints([Point(0, 0), Point(94911151, 94911150), Point(94911152, 94911151)])

# print s.maxPoints([Point(0, 0), Point(1, 1), Point(1, -1)])
