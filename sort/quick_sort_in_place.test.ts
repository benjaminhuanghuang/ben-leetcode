import { quickSortInPlace } from "./quick_sort_in_place"; // Adjust import path as needed

describe("Quick Sort", () => {
  it("should correctly sort an array of numbers", () => {
    const unsortedArray = [5, 2, 9, 1, 5, 6];
    const sortedArray = [1, 2, 5, 5, 6, 9];
    quickSortInPlace(unsortedArray);

    expect(unsortedArray).toEqual(sortedArray);
  });

  it("should handle an empty array", () => {
    const emptyArray: number[] = [];
    quickSortInPlace(emptyArray);

    expect(emptyArray).toEqual([]);
  });

  it("should handle an array with a single element", () => {
    const singleElementArray = [42];
    quickSortInPlace(singleElementArray);

    expect(singleElementArray).toEqual([42]);
  });

  it("should handle already sorted array", () => {
    const sortedArray = [1, 2, 3, 4, 5];
    quickSortInPlace(sortedArray);

    expect(sortedArray).toEqual(sortedArray);
  });

  it("should correctly sort an array with negative numbers", () => {
    const unsortedArray = [-5, 2, -9, 1, 0, 6];
    const sortedArray = [-9, -5, 0, 1, 2, 6];
    quickSortInPlace(unsortedArray);

    expect(unsortedArray).toEqual(sortedArray);
  });

  it("should correctly sort large arrays", () => {
    const unsortedArray = Array.from({ length: 1000 }, () =>
      Math.floor(Math.random() * 1000)
    );
    const sortedArray = [...unsortedArray].sort((a, b) => a - b);
    quickSortInPlace(unsortedArray);

    expect(unsortedArray).toEqual(sortedArray);
  });
});
