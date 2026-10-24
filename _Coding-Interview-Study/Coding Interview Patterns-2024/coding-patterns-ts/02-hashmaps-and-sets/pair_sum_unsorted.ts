/*
    Time Complexity: O(N) where N is the length of the input array.
    Space Complexity: O(N) for the hash map used to store elements.
*/
export function pairSumUnsorted(nums: number[], target: number): number[] {
  const hashMap: { [key: number]: number } = {};

  for (let i = 0; i < nums.length; i++) {
    if (hashMap[target - nums[i]] !== undefined)
      return [hashMap[target - nums[i]], i];
    hashMap[nums[i]] = i;
  }
  return [];
}
