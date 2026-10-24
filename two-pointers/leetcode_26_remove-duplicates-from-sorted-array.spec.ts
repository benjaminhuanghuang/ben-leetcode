import { removeDuplicates } from "./leetcode_26_remove-duplicates-from-sorted-array"; // Adjust import path as needed

describe("removeDuplicates", () => {
  it("case 1", () => {
    const n = removeDuplicates([1, 1, 2]);

    expect(n).toEqual(2);
  });
});
