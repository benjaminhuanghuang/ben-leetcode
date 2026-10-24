import { describe, it, expect } from "vitest";
import { RandomizedCollection } from "./leetcode_381_insert-delete-getrandom-o1-duplicates-allowed";

describe("RandomizedCollection", () => {
  it("should handle the provided test case with duplicates", () => {
    const collection = new RandomizedCollection();

    expect(collection.insert(4)).toBe(true); // First occurrence of 4
    expect(collection.insert(3)).toBe(true); // First occurrence of 3
    expect(collection.insert(4)).toBe(false); // Duplicate of 4
    expect(collection.insert(2)).toBe(true); // First occurrence of 2
    expect(collection.insert(4)).toBe(false); // Another duplicate of 4
    expect(collection.remove(4)).toBe(true); // Remove one occurrence of 4
    expect(collection.remove(3)).toBe(true); // Remove 3
    expect(collection.remove(4)).toBe(true); // Remove another occurrence of 4
    expect(collection.remove(4)).toBe(true); // Remove last occurrence of 4
  });

  it("should return false when removing non-existent value", () => {
    const collection = new RandomizedCollection();

    expect(collection.remove(1)).toBe(false);
  });

  it("should handle multiple insertions and deletions", () => {
    const collection = new RandomizedCollection();

    expect(collection.insert(1)).toBe(true);
    expect(collection.insert(1)).toBe(false);
    expect(collection.insert(2)).toBe(true);
    expect(collection.remove(1)).toBe(true);
    expect(collection.remove(1)).toBe(true);
    expect(collection.remove(1)).toBe(false);
  });

  it("should return random values from collection", () => {
    const collection = new RandomizedCollection();

    collection.insert(1);
    collection.insert(2);
    collection.insert(1);

    const random = collection.getRandom();
    expect([1, 2]).toContain(random);
  });
});
