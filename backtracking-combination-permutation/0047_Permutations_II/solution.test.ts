import { permuteUnique } from "./leetcode_47_permutations-ii";

describe("Test cases for leetcode_47_permutations-ii", () => {
  it("Permute unique", () => {
    expect(permuteUnique([1, 1, 2])).toEqual([
      [1, 1, 2],
      [1, 2, 1],
      [2, 1, 1],
    ]);
  });
});
