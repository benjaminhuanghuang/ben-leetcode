import {
  TreeSet,
  containsNearbyAlmostDuplicate,
} from "./leetcode_220_contains-duplicate-III";

describe("Test cases for leetcode_220_contains-duplicate-iii", () => {
  it("should return true for containsNearbyAlmostDuplicate", () => {
    expect(containsNearbyAlmostDuplicate([1, 2, 3, 1], 3, 0)).toBe(true);
    //expect(containsNearbyAlmostDuplicate([1, 0, 1, 1], 1, 2)).toBe(true);
    //expect(containsNearbyAlmostDuplicate([1, 5, 9, 1, 5, 9], 2, 3)).toBe(false);
  });
});

describe("Test cases for TreeSet", () => {
  it("should return true for TreeSet", () => {
    const treeSet = new TreeSet<number>();
    treeSet.add(1);
    treeSet.add(3);
    treeSet.add(2);
    treeSet.add(5);
    treeSet.add(4);
    expect(treeSet.elements).toEqual([1, 2, 3, 4, 5]);
    treeSet.remove(3);
    expect(treeSet.elements).toEqual([1, 2, 4, 5]);
    expect(treeSet.ceil(3)).toBe(2); //i[2]
    expect(treeSet.floor(2)).toBe(0); // i[0]
  });
});
