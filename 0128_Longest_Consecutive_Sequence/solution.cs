/*
128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
using System.Linq;
using System.Collections.Generic;

public class Solution128 {
    public int LongestConsecutive(int[] nums) {
        var longestconsecutive = 0;
        var dictionary = new Dictionary<int, bool>();
        foreach (var i in nums)
        {
            if (!dictionary.ContainsKey(i))
            {
                dictionary.Add(i, false);
            }
        }
        //nums.ToDictionary(i => i, i => false);

        foreach (var i in nums)
        {
            var index = i;
            if (!dictionary[i])
            {
                // set dict value to true
                dictionary[i] = true;
                var count = 1;

                // search ++
                var increase = index + 1;
                while (dictionary.ContainsKey(increase) && !dictionary[increase])
                {
                    dictionary[increase++] = true;
                    count++;
                }

                // search--
                var decrease = index - 1;
                while (dictionary.ContainsKey(decrease) && !dictionary[decrease])
                {
                    dictionary[decrease--] = true;
                    count++;
                }

                if (count > longestconsecutive)
                {
                    longestconsecutive = count;
                }
            }
        }

        return longestconsecutive;
    }
}