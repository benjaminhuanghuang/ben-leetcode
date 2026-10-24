/*
1608. Special Array With X Elements Greater Than or Equal X

https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

find X such that X is the number of elements in the array that are greater than or equal to X.

- 274. H-Index
*/

/*
https://www.youtube.com/watch?v=EyB0iYwKF84

Why the X is unique?
Suppose there are a numbers which value >= a and there are b numbers which value >= b
if a < b, that means a > b


*/
function specialArray(nums: number[]): number {
  const length = nums.length;
  let left = 0;
  let right = length;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    // Calculate the count of numbers that are greater than or equal to mid
    const count = nums.reduce(
      (accumulator, value) => accumulator + (value >= mid ? 1 : 0),
      0
    );
    // for (auto x: nums)
    //    if (x>=mid) count++;

    // If count equals mid, we found a special number, so return it
    if (count === mid) {
      return mid;
    } else if (count > mid) {
      left = mid + 1;
    } else {
      // If count is less than mid, we need to search in the lower half of the range
      right = mid - 1;
    }
  }

  // If we exit the loop without finding a special number, return -1
  return -1;
}
