/*
381. Insert Delete GetRandom O(1) - Duplicates allowed

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
*/

/*
valuesList: number[] use for getRandom
valueToIndices: Map<number, Set<number>> use for tracking indices of each value, support O(1) insert and remove
*/
export class RandomizedCollection {
  // Map to store value -> set of indices where this value appears in the list
  private valueToIndices: Map<number, Set<number>> = new Map();
  // Array to store all values (allows duplicates)
  private valuesList: number[] = [];

  constructor() {
    this.valuesList = [];
    this.valueToIndices = new Map();
  }

  //
  insert(val: number): boolean {
    // Get or create a set of indices for this value
    if (!this.valueToIndices.has(val)) {
      this.valueToIndices.set(val, new Set());
    }

    // Add the current index (size of array) to the set of indices for this value
    const indicesSet = this.valueToIndices.get(val)!;
    indicesSet.add(this.valuesList.length);

    // Add the value to the end of the array
    this.valuesList.push(val);

    // Return true if this was the first occurrence of the value (set size is 1)
    return indicesSet.size === 1;
  }

  /**
   * Removes a value from the collection.
   * Returns true if the collection contained the specified element.
   */
  remove(val: number): boolean {
    // Check if the value exists in the collection
    if (!this.valueToIndices.has(val)) {
      return false;
    }

    // Get the set of indices for the value to be removed
    const indicesSet = this.valueToIndices.get(val)!;
    // Get any index of the value to be removed (first element from the set)
    const indexToRemove = indicesSet.values().next().value!;
    // Get the index of the last element in the array
    const lastIndex = this.valuesList.length - 1;

    // Get the value at the last position
    const lastValue = this.valuesList[lastIndex];

    // Swap the element to be removed with the last element
    // This allows O(1) removal from the array
    this.valuesList[indexToRemove] = lastValue;

    // Remove the index from the set of indices for the value being removed
    indicesSet.delete(indexToRemove);

    // Update indices for the value that was swapped from the last position
    if (indexToRemove < lastIndex) {
      // Get the set of indices for the last value
      const lastValueIndicesSet = this.valueToIndices.get(lastValue)!;
      // Remove the old last index from the set
      lastValueIndicesSet.delete(lastIndex);
      // Add the new index where the last value was moved to
      lastValueIndicesSet.add(indexToRemove);
    }

    // If no more indices exist for the removed value, remove it from the map
    if (indicesSet.size === 0) {
      this.valueToIndices.delete(val);
    }

    // Remove the last element from the array (which is now a duplicate or was swapped)
    this.valuesList.pop();

    return true;
  }

  /**
   * Get a random element from the collection.
   */
  getRandom(): number {
    const size = this.valuesList.length;
    // Return -1 if the collection is empty, otherwise return a random element
    if (size === 0) {
      return -1;
    }

    // Generate random index and return the element at that index
    const randomIndex = Math.floor(Math.random() * size);
    return this.valuesList[randomIndex];
  }
}
