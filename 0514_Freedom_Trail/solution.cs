/*
514. Freedom Trail

In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial 
called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open 
the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, 
which represents the keyword needs to be spelled. You need to find the minimum number of steps in 
order to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the 
characters in the string key one by one by rotating the ring clockwise or anticlockwise to make 
each character of the string key aligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final 
purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, 
where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button
 to spell, which also counts as 1 step. After the pressing, you could begin to spell the next 
character in the key (next stage), otherwise, you've finished all the spelling.

Example:

Input: ring = "godding", key = "gd"
Output: 4
Explanation:
 For the first key character 'g', since it is already in place, we just need 1 step to spell this 
 character. 
 For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps 
 to make it become "ddinggo".
 Also, we need 1 more step for spelling.

 So the final output is 4.
Note:
Length of both ring and key will be in range 1 to 100.
There are only lowercase letters in both strings and might be some duplcate characters in both 
strings.
It's guaranteed that string key could always be spelled by rotating the string ring.
*/




using System;
using System.Collections.Generic;

public class Solution514
{
    /*
    http://bookshadow.com/weblog/2017/03/05/leetcode-freedom-trail/
    利用字典dp记录当拨盘位于某位置时，所需的最少步数。
    状态转移方程：
    dp[k][i] = min(dp[k][i], dp[k - 1][j] + min(abs(i - j), len(ring) - abs(i - j)))

    其中k表示当前字符在key中的下标，i表示当前字符在ring中的下标，j表示上一个字符在ring中的下标。
    */
    public int FindRotateSteps(string ring, string key)
    {
        // dict, index of each char in ring, each char can appear multiple times
        Dictionary<char, List<int>> ringCharIndex = new Dictionary<char, List<int>>();

        for (int i = 0; i < ring.Length; i++)
        {
            if (!ringCharIndex.ContainsKey(ring[i]))
                ringCharIndex[ring[i]] = new List<int>();
            ringCharIndex[ring[i]].Add(i);
        }

        // Steps for each
        // Key: each position of the ring, Value: min steps
        Dictionary<int, int> pos_steps = new Dictionary<int, int>();

        pos_steps[0] = 0;
        for (int i = 0; i < key.Length; i++)
        {
            char currKeyChar = key[i];
            Dictionary<int, int> newSteps = new Dictionary<int, int>();
            foreach (int lastPos in pos_steps.Keys)
            {
                // how many step needed to move 
                foreach (int rCharIndex in ringCharIndex[currKeyChar])
                {
                    int disAnticlockwise = (lastPos - rCharIndex) >= 0 ? lastPos - rCharIndex : lastPos - rCharIndex + ring.Length;
                    int disClockwise = (rCharIndex - lastPos) >= 0 ? rCharIndex - lastPos : rCharIndex - lastPos + ring.Length;
                    if (newSteps.ContainsKey(rCharIndex))
                        newSteps[rCharIndex] = Math.Min(newSteps[rCharIndex], Math.Min(disAnticlockwise, disClockwise) + pos_steps[lastPos]);
                    else
                        newSteps[rCharIndex] = Math.Min(disAnticlockwise, disClockwise) + pos_steps[lastPos];
                }
            }
            pos_steps = newSteps;
        }

        int minSteps = int.MaxValue;
        foreach (int step in pos_steps.Values)
        {
            Console.WriteLine(step);
            minSteps = Math.Min(step, minSteps);
        }
        return minSteps + key.Length;
    }
    private List<int> ans = new List<int>();

    /* 
    错误解法：
    当ring中有重复字符时，可以顺时针转，也可以逆时针转，这个决定可能会影响下一步的操作，
    导致无法做到最小步数
    */
    public int FindRotateSteps_My(string ring, string key)
    {
        helper(ring, key, 0);
        ans.Sort();
        return ans[0];
    }
    private void helper(string ring, string key, int step)
    {
        if (key.Length == 0)
        {
            ans.Add(step);
            return;
        }
        int distance = calculateDistance(ring, key);
        step += Math.Abs(distance);
        step += 1;
        helper(nextRing(ring, distance), key.Substring(1, key.Length - 1), step);
    }
    private string nextRing(string ring, int distance)
    {
        distance = (ring.Length + distance) % ring.Length;
        return ring.Substring(distance, ring.Length - distance) + ring.Substring(0, distance);
    }

    // If there are same chars in the ring, need check each position
    private int calculateDistance(string ring, string key)
    {
        int index = ring.IndexOf(key[0]);
        int disAnticlockwise = index;

        int backIndex = this.backIndex(ring, key[0]);
        int disClockwise = ring.Length - backIndex;
        if (disAnticlockwise < disClockwise)   // Need check each position, not 2
            return disAnticlockwise;
        else
            return -disClockwise;
    }

    private int backIndex(string s, char c)
    {
        for (int i = s.Length - 1; i >= 0; i--)
        {
            if (s[i] == c)
                return i;
        }
        return -1;
    }
}