/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
  let res = [];
  helper(nums, res, 0, []);
  return res;
};

function helper(nums,  res,  start, combination) {
  res.push([...combination]);

  for (let i = start; i < nums.length; i++) {
      combination.push(nums[i]);
      helper(nums, res, i + 1, combination);
      combination.pop();
  }
}