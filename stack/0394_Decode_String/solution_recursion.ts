/*
  Recursive descent: use a shared index `i` that both the outer and
  inner recursive calls advance. Each call to decode() parses one
  "level" — a run of letters and k[...] groups — and returns as soon
  as it hits ']' (end of its level) or the end of the string.
*/
function decodeString(s: string): string {
  let i = 0;

  function decode(): string {
    let str = "";
    // stop when ]
    while (i < s.length && s[i] !== "]") {
      // s[i] is number
      if (s[i] >= "0" && s[i] <= "9") {
        let num = 0;
        while (s[i] >= "0" && s[i] <= "9") {
          num = num * 10 + Number(s[i]);
          i++;
        }
        i++; // skip '['
        const inner = decode(); // recurse into the nested group
        i++; // skip ']'
        str += inner.repeat(num);
      } else {
        str += s[i];
        i++;
      }
    }

    return str;
  }

  return decode();
}

export {};
