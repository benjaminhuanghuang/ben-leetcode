/*

81. Search in Rotated Sorted Array II

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
*/

/* 
   4 5 6 7 1 0 2
   
    left part/
              /right part
*/
function search(nums: number[], target: number): boolean {
  if (nums.length == 0) return false;

  let l = 0;
  let r = nums.length - 1;

  while (l <= r) {
    let mid = l + Math.floor((r - l) / 2);
    if (nums[mid] == target) {
      return true;
    }

    if (nums[l] < nums[mid]) {
      // mid located in left part, which is increasing
      if (nums[l] <= target && target < nums[mid])
        //  target located between left and mid
        r = mid - 1;
      //  target is bigger than mid
      else l = mid + 1;
    } else if (nums[l] > nums[mid]) {
      // mid located in right part, which is increasing
      if (nums[mid] < target && target <= nums[r])
        //target located between mid and right
        l = mid + 1;
      // target is less than mid
      else r = mid - 1;
    } else {
      // nums[l] == nums[mid]，无法判断，跳过左边
      l++;
    }
  }
  return false;
}
