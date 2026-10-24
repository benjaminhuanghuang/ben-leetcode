/*
134. Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station 
i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

*/

public class Solution134 {
    // when we check gas left(start from x, end y), if gas left < 0, we can make sure that it could not 
    // start from any point between x and y. and the potential start point would be y + 1, and 
    // reset the gas left to 0;
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        var gasLeft = 0;
        var total = 0;
        var start = 0;
        for (int i = 0; i < gas.Length; i++)
        {
            gasLeft += gas[i] - cost[i];
            if (gasLeft < 0)
            {
                start = i + 1;
                total += gasLeft;
                gasLeft = 0;
            }
        }
        // total + gasLeft is sum(gas) - sum(cost)
        //reduce the 2 times traversal to just 1 time.
        return total + gasLeft < 0 ? -1 : start;
    }

    //  start point and end point in 0, if sum >= 0 move end point, if sum < 0, move start point backward until sum >= 0.
    public int CanCompleteCircuit_2(int[] gas, int[] cost)
    {
        var len = gas.Length;
        var start = 0;
        var end = 0;
        var sum = 0;

        while (true)
        {
            sum += gas[end] - cost[end];
            end = (end + 1)%len;
            while (sum < 0)                 
            {                     
                if (start == end) break;                     
                start = (start - 1 + len)%len;                     
                sum += gas[start] - cost[start];                 
            }                 
            if (start == end)                 
            {                     
                if (sum >= 0) return start;
                return -1;
            }
        }
    }
}