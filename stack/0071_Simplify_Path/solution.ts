/*
71. Simplify Path
https://leetcode.com/problems/simplify-path/
*/

function simplifyPath(path: string): string {
  const stack: string[] = [];
  const parts = path.split("/");

  for (const part of parts) {
    if (part === "" || part === ".") {
      continue;
    } else if (part === "..") {
      stack.pop();
    } else {
      stack.push(part);
    }
  }
  return "/" + stack.join("/");
}
