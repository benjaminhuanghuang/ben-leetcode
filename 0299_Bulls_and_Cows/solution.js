/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
  let bulls = 0;
  let cows = 0;
  //而index对应的元素值表示secret中该index出现的次数。
  //如果secret出现一次某个数字，该位置就自增1，如果此时该位置小于0，就说明这个数字在guess出现过，因此cows就自增1；
  // guess的处理和secret类似，区别就是index对应元素需要自减。
  let numbers = new Array(10).fill(0);
  for (let i = 0; i < secret.length; i++) {
      if (secret[i] == guess[i])
          bulls++;
      else {
          if (numbers[secret.charCodeAt(i) - '0'.charCodeAt(0)]++ < 0)
              cows++;
          if (numbers[guess.charCodeAt(i) - '0'.charCodeAt(0)]-- > 0)
              cows++;
      }
  }
  return `${bulls}A${cows}B`;
};