import collections


class Solution(object):
    # http://bookshadow.com/weblog/2016/09/18/leetcode-frog-jump/
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        q = collections.deque()
        visited = collections.defaultdict(lambda: collections.defaultdict(bool))
        stoneSet = set(stones)
        q.append((0, 0))  # (x,y) x=position, y= distance of last jump
        visited[0][0] = True
        while q:
            x, y = q.popleft()
            if x == stones[-1]:
                return True
            for z in (y - 1, y, y + 1):
                if z > 0 and not visited[x + z][z] and x + z in stoneSet:
                    visited[x + z][z] = True
                    q.append((x + z, z))
        return False
