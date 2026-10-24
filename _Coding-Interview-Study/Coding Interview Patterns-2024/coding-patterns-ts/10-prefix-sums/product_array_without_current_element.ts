/*

Given an array of integers, return an array res so that res[i] is equal to the product of all
the elements of the input array except nums [ i] itself.

res[i] = 左边所有元素的乘积 × 右边所有元素的乘积
*/
function product_array_without_current_element(nums: number[]): number[] {
  const n = nums.length;
  const res: number[] = new Array(n).fill(1);

  // Populate the output with the running left product.
  // res[i] = nums[0] * nums[1] * ... * nums[i - 1]
  for (let i = 1; i < n; i++) {
    res[i] = res[i - 1] * nums[i - 1];
  }

  // Multiply the output with the running right product, from right to
  // left.
  let rightProduct = 1;
  for (let i = n - 1; i >= 0; i--) {
    res[i] *= rightProduct;
    rightProduct *= nums[i];
  }

  return res;
}

/*
Time complexity: The time complexity o~ product_array_without_current_element is O(n)
because we iterate over the nums array twice.

Space complexity: The space complexity is O(1). The res array is not included in the space complexity
analysis.
*/
