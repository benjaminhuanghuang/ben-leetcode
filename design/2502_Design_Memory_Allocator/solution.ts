/*
2502. Design Memory Allocator

https://leetcode.com/problems/design-memory-allocator/
*/
interface MemoryBlock {
  [endpoint: number]: number;
}

interface AllocationRecord {
  [mID: number]: number[];
}

class Allocator {
  // Create memoryTree as a global variable to track start and end points of allocated memory blocks
  memoryTree: MemoryBlock = {};

  // Create allocations as a global variable to record allocations by mID
  allocations: AllocationRecord = {};
  constructor(public n: number) {}

  allocate(size: number, mID: number): number {
    let start = -1;

    // Find a suitable free block
    for (let i = 0; i <= this.n - size; i++) {
      let isFree = true;

      // Check if the block from i to i + size - 1 is free
      for (let j = i; j < i + size; j++) {
        if (this.memoryTree[j] !== undefined) {
          isFree = false;
          break;
        }
      }

      if (isFree) {
        start = i;
        break;
      }
    }

    if (start === -1) {
      return -1; // Not enough space
    }

    // Allocate the block
    this.memoryTree[start] = start + size - 1;

    // Record the allocation
    if (!this.allocations[mID]) {
      this.allocations[mID] = [];
    }
    this.allocations[mID].push(start);

    return start;
  }

  free(mID: number): number {
    let totalFreedSize: number = 0; // Counter for total freed memory size

    // Check if there are allocations for the given mID
    if (this.allocations[mID]) {
      // Iterate over all start points of blocks associated with mID
      for (let start of this.allocations[mID]) {
        let end = this.memoryTree[start]; // Fetch the corresponding end point
        // Calculate size of the current block to increment the total freed size
        totalFreedSize += end - start + 1;
        // Remove the block from the memory allocation tree
        delete this.memoryTree[start];
      }
      // Remove mID from the allocation record
      delete this.allocations[mID];
    }

    // Return the total size of all freed blocks
    return totalFreedSize;
  }
}
