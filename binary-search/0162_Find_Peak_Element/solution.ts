/*
162. Find Peak Element

https://leetcode.com/problems/find-peak-element/
*/

/*
2. 如果mid处于上升区间，说明peak在右边
3. 如果mid处于下降区间，说明peak在左边
4. 如果mid处于peak，返回mid
*/

function findPeakElement(nums: number[]): number {
  let low = 0;
  let high = nums.length - 1;
  while (low <= high) {
    let mid = Math.floor((high - low) / 2) + low;
    // 如果[mid-1]>[mid]，那么peak肯定在[low]和[mid-1]之间（闭区间）
    // 下降区间， peak在左边， high = mid - 1
    if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) high = mid - 1;
    // 如果mid+1大，那么peak肯定在mid+1和hi之间（闭区间）
    else if (mid + 1 < nums.length && nums[mid] < nums[mid + 1]) low = mid + 1;
    // 其他情况（peak在开头或者结尾，或者中间）
    else return mid;
  }
  return -1;
}
