function sortArray(nums: number[]): number[] {
  mergeSort(nums, 0, nums.length);
  return nums;
}

function mergeSort(nums: number[], low: number, high: number) {
  if (high <= low) {
    return;
  }
  const mid = Math.floor((low + high) / 2);
  mergeSort(nums, low, mid);
  mergeSort(nums, mid + 1, high);
  merge(nums, low, mid, high);
}

function merge(nums: number[], low: number, mid: number, high: number) {
  const lArr = nums.slice(low, mid + 1);
  const rArr = nums.slice(mid + 1, high + 1);

  let p1 = 0,
    p2 = 0;
  let i = low;
  while (p1 < lArr.length && p2 < rArr.length) {
    if (lArr[p1] < rArr[p2]) {
      nums[i] = lArr[p1];
      p1++;
    } else {
      nums[i] = rArr[p2];
      p2++;
    }
    i++;
  }

  while (p1 < lArr.length) {
    nums[i] = lArr[p1];
    i++;
    p1++;
  }
  while (p2 < rArr.length) {
    nums[i] = rArr[p2];
    i++;
    p2++;
  }
}
