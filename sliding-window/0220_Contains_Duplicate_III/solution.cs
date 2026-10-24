using System.Collections.Generic;

public class Solution220 {
    //https://miafish.wordpress.com/2015/06/19/leetcode-ojc-contains-duplicate/
    public bool ContainsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        var buckets = new Dictionary<long, long>();
        if (t < 0) 
            return false;
        for (int i = 0; i < nums.Length; i++)             
        {                 
            var bucketIndex = ((long) nums[i] - int.MinValue)/((long) t + 1);                 
            if (i - k - 1 >= 0)
            {
                buckets.Remove(((long)nums[i - k - 1] - int.MinValue) / ((long)t + 1));
            }

            if (buckets.ContainsKey(bucketIndex)
                || buckets.ContainsKey(bucketIndex - 1) && nums[i] - buckets[bucketIndex - 1] <= t
                || buckets.ContainsKey(bucketIndex + 1) && buckets[bucketIndex + 1] - nums[i] <= t)
                return true;
            buckets[bucketIndex] = nums[i];
        }

        return false;
    }
}

