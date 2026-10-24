public class Solution033 {
    // if mid is greater than low, then we know mid is in the left part. 
    //  if x >= low and x < mid. search left part, otherwise search right part;
    // if mid is less than low, then we know mid is in the right part. 
    //  if x <= high and x > mid. search the right part, otherwise search left part;
    // if mid is equal to low, just increase the low (we do not know where the target x would be)
    public int Search(int[] nums, int target) {
        if (nums == null || nums.Length < 1)
            return -1;

        int left = 0;
        int right = nums.Length -1;

        while (left <= right)
        {
            if (nums[left] == target)
                return left;
            if (nums[right] == target)
                return right;

            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > nums[left]) // mid located in left part, which is increasing
            {
                if (nums[left] < target && target < nums[mid]) //  target located between left and mid
                    right = mid -1;
                else   //  target is bigger than mid
                    left = mid + 1;
            }
            else                       // mid located in right part, which is increasing
            {
                if (nums[mid] < target && target < nums[right])   //target located between mid and right
                    left = mid + 1;
                else   // target is less then mid
                    right = mid - 1;
            }
        }

        return -1;
    }
}