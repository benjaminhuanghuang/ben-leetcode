import { calculate, calculate2 } from "./leetcode_224_basic-calculator";

describe("Basic Calculator", () => {
  it("Test case 1", () => {
    const s = "1 + 1";
    expect(calculate(s)).toBe(2);
  });
});

describe("Basic Calculator2", () => {
  it("Test case 1", () => {
    const s = "1 + 1";
    expect(calculate2(s)).toBe(2);
  });

  xit("Test case 1", () => {
    const s = "3-(1 + 1)";
    expect(calculate2(s)).toBe(1);
  });
  xit("Test case 2", () => {
    const s = " 2-1 + 2 ";
    expect(calculate2(s)).toBe(3);
  });

  it("Test case 3", () => {
    const s = " 2147483647 ";
    expect(calculate2(s)).toBe(2147483647);
  });
});
