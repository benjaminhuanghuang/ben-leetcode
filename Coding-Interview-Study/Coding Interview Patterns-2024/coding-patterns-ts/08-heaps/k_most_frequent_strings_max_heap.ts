function k_most_frequent_strings_max_heap(strs: string[], k: number): string[] {
  // Count frequencies of each string
  const freqMap = new Map<string, number>();
  for (const s of strs) {
    freqMap.set(s, (freqMap.get(s) || 0) + 1);
  }

  // Custom comparator for max heap
  // If frequency equal, compare lexicographically
  const heap = new MaxHeap<Pair>((a, b) => {
    if (a.freq === b.freq) return a.str < b.str;
    return a.freq > b.freq;
  });

  // Push all pairs into heap
  for (const [str, freq] of freqMap.entries()) {
    heap.push(new Pair(str, freq));
  }

  // Extract top k elements
  const res: string[] = [];
  for (let i = 0; i < k && !heap.isEmpty(); i++) {
    const top = heap.pop();
    if (top) res.push(top.str);
  }

  return res;
}
/*
Time complexity: The time complexity of k_most_frequent_strings_max_heap is O(n+k log(n)).
• It takes O(n) time to count the frequency of each string using Counter, and to build the
max_heap.
• We also pop off the top of the heap k times, with each pop operation taking O(log(n)) time.
Therefore, the overall time complexity is O(n) + k * O(log(n)) = O(n + k * log(n)).

Space complexity: The space complexity is O(n) because the hash map and heap store at most n
pairs. Note that the output array is not considered in the space complexity.
*/
