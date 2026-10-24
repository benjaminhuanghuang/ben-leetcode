import { minimumTotal } from "./leetcode_120_triangle";

describe("minimumTotal", () => {
  it("should return the minimum path sum from top to bottom", () => {
    expect(minimumTotal([[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]])).toBe(11);
  });
});
