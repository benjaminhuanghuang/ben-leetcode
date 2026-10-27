import { calculate } from "./solution-common.js";

describe("Basic Calculator (recursive descent, common solution)", () => {
  it("simple addition", () => {
    expect(calculate("1 + 1")).toBe(2);
  });

  it("addition and subtraction with spaces", () => {
    expect(calculate(" 2-1 + 2 ")).toBe(3);
  });

  it("nested parentheses", () => {
    expect(calculate("(1+(4+5+2)-3)+(6+8)")).toBe(23);
  });

  it("unary minus before parentheses", () => {
    expect(calculate("-(2+3)")).toBe(-5);
  });

  it("unary minus at expression start", () => {
    expect(calculate("-2+ 2")).toBe(0);
  });

  it("unary plus at expression start", () => {
    expect(calculate("+2-3")).toBe(-1);
  });

  it("single number", () => {
    expect(calculate(" 2147483647 ")).toBe(2147483647);
  });

  it("double negative inside parentheses", () => {
    expect(calculate("-(-(2+3))")).toBe(5);
  });
});
