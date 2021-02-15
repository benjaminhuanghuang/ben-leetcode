function convertToRoman(num) {
  let values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
  let strs = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

  let ans = "";

  for (let i = 0; i < values.length; i++) {
    while (num >= values[i]) {
      num -= values[i];
      ans += strs[i];
    }
  }
  return ans;
}
