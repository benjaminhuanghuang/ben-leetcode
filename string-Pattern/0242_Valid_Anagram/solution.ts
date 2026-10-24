/*
    Count the frequency of each character in both strings.
*/
function isAnagram(s: string, t: string): boolean {
  if (s.length !== t.length) return false;

  const map = new Map<string, number>();

  for (let i = 0; i < s.length; i++) {
    map.set(s[i], (map.get(s[i]) || 0) + 1);
    map.set(t[i], (map.get(t[i]) || 0) - 1);
  }

  for (const [key, value] of map) {
    if (value !== 0) return false;
  }
  return true;
}
