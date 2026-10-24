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