/*
Key point: If we know what the top k largest integers are, we'd know
that the smallest of these would be the kth largest integer.
Instead of sorting the entire array, we can keep track of the top k largest
integers in the array.


Time complexity: O(n log(k)) because for each integer, we perform at most one push and pop operation on the min-heap, which has a
size no larger than k. Each heap operation takes O(log(k)) time.

Space complexity: The space complexity is O(k) because the heap can grow to a size of k.

*/
function kth_largest_int_min_heap(nums: number[], k: number): number {
  // Min-heap to store the top k largest integers.
  const minHeap: number[] = [];

  for (const num of nums) {
    // Ensure the heap has at least 'k' integers.
    if (minHeap.length < k) {
      heapPush(minHeap, num);
    }
    // If 'num' is greater than the smallest integer in the heap, pop
    // off this smallest integer from the heap and push in 'num'.
    else if (num > minHeap[0]) {
      heapPop(minHeap);
      heapPush(minHeap, num);
    }
  }

  return minHeap[0];
}

// Helper function to push an element onto the min heap
function heapPush(heap: number[], value: number): void {
  heap.push(value);
  let i = heap.length - 1;

  // Bubble up
  while (i > 0) {
    const parent = Math.floor((i - 1) / 2);
    if (heap[i] < heap[parent]) {
      [heap[i], heap[parent]] = [heap[parent], heap[i]];
      i = parent;
    } else {
      break;
    }
  }
}

// Helper function to pop the minimum element from the min heap
function heapPop(heap: number[]): number | undefined {
  if (heap.length === 0) return undefined;
  if (heap.length === 1) return heap.pop();

  const min = heap[0];
  heap[0] = heap.pop()!;
  let i = 0;

  // Bubble down
  while (true) {
    const left = 2 * i + 1;
    const right = 2 * i + 2;
    let smallest = i;

    if (left < heap.length && heap[left] < heap[smallest]) {
      smallest = left;
    }
    if (right < heap.length && heap[right] < heap[smallest]) {
      smallest = right;
    }

    if (smallest !== i) {
      [heap[i], heap[smallest]] = [heap[smallest], heap[i]];
      i = smallest;
    } else {
      break;
    }
  }

  return min;
}
