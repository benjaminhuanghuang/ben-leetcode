/*
2671. Frequency Tracker

https://binarysearch.com/problems/Frequency-Tracker
*/

class FrequencyTracker {
  // This map keeps track of the count of each number.
  countMap: Map<number, number> = new Map();

  // This map keeps track of the frequency of each count.
  frequencyMap: Map<number, number> = new Map();
  constructor() {}

  add(num: number) {
    const currentCount = this.countMap.get(num) || 0;

    // if nums's count is 3, change then we need to decrement the frequency of 3 and increment the frequency of 4.
    if (currentCount > 0) {
      this.frequencyMap.set(
        currentCount,
        (this.frequencyMap.get(currentCount) || 0) - 1
      );
    }

    // Increase the count of the number.
    this.countMap.set(num, currentCount + 1);

    // Increase the frequency of the new count.
    this.frequencyMap.set(
      currentCount + 1,
      (this.frequencyMap.get(currentCount + 1) || 0) + 1
    );
  }

  deleteOne(num: number) {
    // Retrieve the current count for the number, default to 0.
    const currentCount = this.countMap.get(num) || 0;

    // If the count is zero, exit the function as there is nothing to delete.
    if (currentCount === 0) {
      return;
    }

    // Decrease the frequency of the current count.
    this.frequencyMap.set(
      currentCount,
      (this.frequencyMap.get(currentCount) || 0) - 1
    );

    // Update the count map to reflect one less of the number.
    if (currentCount - 1 > 0) {
      this.countMap.set(num, currentCount - 1);
      this.frequencyMap.set(
        currentCount - 1,
        (this.frequencyMap.get(currentCount - 1) || 0) + 1
      );
    } else {
      // If the new count is 0, remove the number from the countMap.
      this.countMap.delete(num);
    }
  }

  hasFrequency(frequency: number): boolean {
    return (this.frequencyMap.get(frequency) || 0) > 0;
  }
}
