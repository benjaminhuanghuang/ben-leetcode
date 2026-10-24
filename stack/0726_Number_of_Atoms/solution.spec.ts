import { countOfAtoms } from "./leetcode_726_number-of-atoms";

describe("Test Number of Atoms", () => {
  it("Test case 1", () => {
    const formula = "H2O";
    expect(countOfAtoms(formula)).toBe("H2O");
  });
});
