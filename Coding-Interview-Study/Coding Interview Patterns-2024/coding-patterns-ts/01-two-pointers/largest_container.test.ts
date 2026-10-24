import { largestContainer } from "./largest_container";

describe("largestContainer", () => {
  it("should return the maximum water that can be contained", () => {
    expect(largestContainer([])).toBe(0);
    expect(largestContainer([1])).toBe(0);
    expect(largestContainer([0, 1, 0])).toBe(0);

    expect(largestContainer([3, 3, 3, 3])).toBe(9);
    expect(largestContainer([1, 2, 3])).toBe(2);
  });
});
