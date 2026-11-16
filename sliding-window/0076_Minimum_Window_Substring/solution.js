/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
function minWindow(s, t) {
  const need = new Map();
  const window = new Map();

  for (const c of t) {
    need.set(c, (need.get(c) || 0) + 1);
  }

  let left = 0;
  let formed = 0;

  const required = need.size;
  let minLength = Infinity;
  let start = 0;

  // Expand window
  for (let right = 0; right < s.length; right++) {
    const char = s[right];
    window.set(char, (window.get(char) || 0) + 1);
    if (need.has(char) && window.get(char) === need.get(char)) formed++;

    //Shrink window
    while (formed === required) {
      if (right - left + 1 < minLength) {
        minLength = right - left + 1;
        start = left;
      }

      const leftChar = s[left];
      window.set(leftChar, window.get(leftChar) - 1);
      // window invalid
      if (need.has(leftChar) && window.get(leftChar) < need.get(leftChar)) {
        formed--;
      }
      left++;
    }
  }

  return minLength === Infinity ? "" : s.slice(start, start + minLength);
}
