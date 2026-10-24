/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function (nums) {
  nums.sort(function (a, b) { return a - b; });
  let res = [];
  helper(nums, res, 0, []);
  return res;
};

function helper(nums, res, start, combination) {
  res.push([...combination]);

  for (let i = start; i < nums.length; i++) {
    if (i != start && nums[i] == nums[i - 1]) {
      continue;
    }
    combination.push(nums[i]);
    helper(nums, res, i + 1, combination);
    combination.pop();
  }
}