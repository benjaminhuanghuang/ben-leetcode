function isHappy(n: number): boolean {
  const visited: { [key: number]: boolean } = {};
  let number = n;

  while (!visited[number]) {
    visited[number] = true;
    let start = number;
    number = 0;

    while (start !== 0) {
      const digit = start % 10;
      number += digit * digit; // number = the sum of the squares of start's digits
      start = Math.floor(start / 10);
    }

    if (number === 1) {
      return true;
    }
  }

  return false;
}
