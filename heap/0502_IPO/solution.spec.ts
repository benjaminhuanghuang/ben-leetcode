import { findMaximizedCapital } from "./leetcode_502_ipo";

describe("IPO", () => {
  it("should return the maximum capital", () => {
    expect(findMaximizedCapital(2, 0, [1, 2, 3], [0, 1, 1])).toEqual(4);
    //expect(findMaximizedCapital(3, 0, [1, 2, 3], [0, 1, 2])).toEqual(6);
  });
});
