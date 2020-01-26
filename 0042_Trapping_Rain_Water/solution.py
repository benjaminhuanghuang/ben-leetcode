'''
42. Trapping Rain Water


Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

reference
    http://www.cnblogs.com/zuoyuan/p/3781453.html
    http://www.lxway.net/898969464.html

'''


class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        leftmosthigh = [0 for i in range(len(height))]
        leftmax = 0
        for i in range(len(height)):
            if height[i] > leftmax:
                leftmax = height[i]
            leftmosthigh[i] = leftmax

        sum = 0
        rightmax = 0
        for i in reversed(range(len(height))):
            if height[i] > rightmax:
                rightmax = height[i]
            if min(rightmax, leftmosthigh[i]) > height[i]:
                sum += min(rightmax, leftmosthigh[i]) - height[i]
        return sum

    # http://www.lxway.net/898969464.html
    def trap_2loop(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0

        max_height = max(height)
        max_index = height.index(max_height)

        result = 0
        max_left_h = 0
        # water count = max_left_h - current_left_h
        for i in xrange(max_index):
            if height[i] > max_left_h:
                max_left_h = height[i]
            else:
                result += max_left_h - height[i]

        max_right_h = 0
        # water count = max_right_h - current_right_h
        for i in xrange(len(height) - 1, max_index, -1):
            if height[i] > max_right_h:
                max_right_h = height[i]
            else:
                result += max_right_h - height[i]

        return result

    # http://www.lxway.net/898969464.html
    def trap_1loop(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0

        result = 0
        left = 0
        right = len(height) - 1
        max_left_height = 0
        max_right_height = 0

        while (left < right):
            if height[left] < height[right]:
                # check left side
                if height[left] < max_left_height:
                    result += max_left_height - height[left]
                else:
                    max_left_height = height[left]
                left += 1
            else:
                if height[right] < max_right_height:
                    result += max_right_height - height[right]
                else:
                    max_right_height = height[right]

                right -= 1

        return result