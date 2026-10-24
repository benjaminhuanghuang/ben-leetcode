/*
658. Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/
*/

function findClosestElements(arr: number[], k: number, x: number): number[] {
  let low = 0;
  let high = arr.length - 1;

  // find the low and hight index of the closest element to x
  while (high - low >= k) {
    if (Math.abs(arr[low] - x) > Math.abs(arr[high] - x)) {
      low++;
    } else {
      high--;
    }
  }

  const result: number[] = [];
  for (let i = low; i <= high; i++) {
    result.push(arr[i]);
  }

  return result;
}
