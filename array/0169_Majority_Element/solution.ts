/*
169. Majority Element
https://leetcode.com/problems/majority-element/
*/

/*
    This method uses Boyer-Moore Voting Algorithm.
    The idea is to cancel out each occurrence of an element e with all the other elements that are different from e.
    This way, if an element has a majority, it will remain after all the cancellations.
*/
function majorityElement(nums: number[]): number {
  let count = 0;
  let candidate = 0;

  for (let num of nums) {
    if (count === 0) {
      candidate = num;
    }

    count += num === candidate ? 1 : -1;
  }

  return candidate;
}
