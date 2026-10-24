function k_most_frequent_strings_min_heap(strs: string[], k: number): string[] {
  // Step 1: Count frequencies
  const freqMap = new Map<string, number>();
  for (const s of strs) {
    freqMap.set(s, (freqMap.get(s) || 0) + 1);
  }

  // Step 2: Create a min heap (lowest frequency has highest priority to be removed)
  const heap = new MinHeap<Pair>((a, b) => {
    if (a.freq === b.freq) return a.str > b.str; // reverse lexicographical for min-heap
    return a.freq < b.freq;
  });

  // Step 3: Push items into heap, pop when heap size > k
  for (const [str, freq] of freqMap.entries()) {
    heap.push(new Pair(str, freq));
    if (heap.size() > k) heap.pop();
  }

  // Step 4: Pop all elements, reverse to get descending order
  const res: string[] = [];
  while (!heap.isEmpty()) {
    const top = heap.pop();
    if (top) res.push(top.str);
  }

  return res.reverse(); // ensure most frequent first
}
/*

Time complexity: The time complexity of k_most_frequent_strings_min_heap is O(n log(k)).
• It takes O(n) time to count the frequency of each string using Counter.
• To populate the heap, we push n words onto it, with each push and pop operation taking
O(log(k)) time. This takes O(n * log(k)) time.
• Then, we extract k strings from the heap by performing the pop operation k times. This takes
O(k * log(k)) time.
• Finally. we reverse the output array, which takes O(k) time.
Therefore, the overall time complexity is O(n) + O(n * log(k)) + O(k * log(k)) + O(k) = O(n * log(k)).

Space complexity: The space complexity is O(n) because the hash map stores at most n pairs,
whereas the heap only takes up O(k) space. The res array is not considered in the space complexity.
*/
