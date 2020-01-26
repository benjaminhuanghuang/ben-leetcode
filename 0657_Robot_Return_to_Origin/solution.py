class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        h = 0
        v = 0
        for m in moves:
            if m == 'U':
                v = v - 1
            elif m == 'D':
                v = v + 1
            elif m == 'L':
                h = h - 1
            elif m == 'R':
                h = h + 1
        return h == 0 and v==0
