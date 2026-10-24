/*
Solution:
https://www.bilibili.com/video/BV16z4y197oQ/?spm_id_from=333.337.search-card.all.click&vd_source=b7025abbc1efd8b7631e43fa506ade3a

anser[i] = product of the numbers at left side of i  * product of the numbers at right side of i

Time complexity: O(N)
Space complexity: O(N)  -> need to optimize to O(1)
*/
function productExceptSelf(nums: number[]): number[] {
  const length = nums.length;
  const L = new Array(length).fill(0);
  const R = new Array(length).fill(0);
  const answer = new Array(length).fill(0);

  // left side
  L[0] = 1;
  for (let i = 1; i < length; i++) {
    L[i] = nums[i - 1] * L[i - 1];
  }

  // right side
  R[length - 1] = 1;
  for (let i = length - 2; i >= 0; i--) {
    R[i] = nums[i + 1] * R[i + 1];
  }

  // Calculate answer
  for (let i = 0; i < length; i++) {
    answer[i] = L[i] * R[i];
  }

  return answer;
}

/*
optimize space complexity to O(1),
use answer array to store the left side product
use R to store the right side product
*/
function productExceptSelf_2(nums: number[]): number[] {
  const length = nums.length;
  const answer = new Array(length).fill(0);

  // left side
  answer[0] = 1;
  for (let i = 1; i < length; i++) {
    answer[i] = nums[i - 1] * answer[i - 1];
  }

  // right side
  let R = 1;
  for (let i = length - 1; i >= 0; i--) {
    answer[i] = answer[i] * R;
    R = R * nums[i];
  }
  return answer;
}
