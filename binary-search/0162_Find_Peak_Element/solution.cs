public class Solution162 {
    //http://blog.csdn.net/u012162613/article/details/41791715
    public int FindPeakElement(int[] nums) {
        int l= 0;
        int r = nums.Length - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}

