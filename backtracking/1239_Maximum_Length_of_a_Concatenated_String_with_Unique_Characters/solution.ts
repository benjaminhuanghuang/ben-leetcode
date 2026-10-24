function maxLength(arr: string[]): number {
  // 1. Filter out strings that have duplicate characters
  // remove strings like "aa" because they can never be used.
  const filtered = arr.filter((s) => new Set(s).size === s.length);

  let maxLen = 0;

  function backtrack(index: number, current: string) {
    maxLen = Math.max(maxLen, current.length);

    for (let i = index; i < filtered.length; i++) {
      const s = filtered[i];
      // Check if s can be added without duplicates
      const set = new Set(current);
      let canAdd = true;
      for (const ch of s) {
        if (set.has(ch)) {
          canAdd = false;
          break;
        }
      }

      if (canAdd) {
        backtrack(i + 1, current + s);
      }
    }
  }

  backtrack(0, "");
  return maxLen;
}
