/*
leetcode.com/problems/encode-and-decode-tinyurl/
*/

const alphabet =
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const urlToCode = new Map<string, string>();
const codeToUrl = new Map<string, string>();
const prefix = "http://tinyurl.com/";

function generateCode(length: number = 6): string {
  let code = "";
  for (let i = 0; i < length; i++) {
    const idx = Math.floor(Math.random() * alphabet.length);
    code += alphabet[idx];
  }
  return code;
}

/**
 * Encodes a URL to a shortened URL.
 */
function encode(longUrl: string): string {
  // Reuse code if URL already encoded
  if (urlToCode.has(longUrl)) {
    return prefix + urlToCode.get(longUrl);
  }

  let code = generateCode();
  while (codeToUrl.has(code)) {
    // avoid collision
    code = generateCode();
  }

  urlToCode.set(longUrl, code);
  codeToUrl.set(code, longUrl);

  return prefix + code;
}

/**
 * Decodes a shortened URL to its original URL.
 */
function decode(shortUrl: string): string {
  const code = shortUrl.replace(prefix, "");
  return codeToUrl.get(code) || "";
}
