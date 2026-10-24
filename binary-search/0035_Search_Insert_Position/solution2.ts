/*
Given a sorted array and a target value, return the index if the target is found. If not,
return the index where it would be if it were inserted in order.

keywords: sorted, finding target

 */
function searchInsert(arr: number[], target: number): number {
  let left = 0;
  let right = arr.length - 1;

  while (left < right) {
    const middle = Math.floor((left + right) / 2);
    if (arr[middle] < target) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }
  // When the loop ends, left must be equal to right and it is a valid index.
  // if arr[left] == target, we return left.
  // If arr[left] > target, that means we are inserting target before arr[left], so we return left.
  // If arr[left] < target, that means we insert target after arr[left], so we return left + 1.
  return arr[left] < target ? left + 1 : left;
}
