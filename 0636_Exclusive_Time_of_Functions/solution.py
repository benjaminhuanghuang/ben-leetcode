class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        stack = []
        times = [0 for i in range(n)]

        for log in logs:
            id, action, time = log.split(':')
            id = int(id)
            time = int(time)
            if action == "start":
                if stack:
                    topId, topTime = stack[-1]
                    # exe
                    times[topId] += time - topTime
                stack.append([id, time])
            else: # action == "end"
                times[stack[-1][0]] += time - stack[-1][1] + 1
                stack.pop()
                if stack: stack[-1][1] = time + 1

        return times


# n = 2
# logs = ["0:start:0",
#  "1:start:2",
#  "1:end:5",
#  "0:end:6"]

n = 3

logs = ["0:start:0", "0:end:0", "1:start:1", "1:end:1", "2:start:2", "2:end:2", "2:start:3", "2:end:3"]
n = 1
logs = ["0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"]

# n = 2
# logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]
n = 2
logs = ["0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"]
solu = Solution()
print solu.exclusiveTime(n, logs)
