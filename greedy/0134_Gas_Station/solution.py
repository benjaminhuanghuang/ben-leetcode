class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """

        if sum(gas) < sum(cost):
            return -1

        total = 0
        gas_left = 0
        index = 0
        for i in range(len(gas)):
            gas_left += gas[i] - cost[i]
            if gas_left < 0:
                index = i + 1
                total += gas_left
                gas_left = 0
        total += gas_left
        return index if total >= 0 else -1
