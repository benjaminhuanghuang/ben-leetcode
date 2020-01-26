'''
134. Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
'''


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
