# Bit Manipulation

一个数字与其自身异或的结果为 0。
一个数字与 0 进行异或得到该数字本身。
XOR 操作顺序不影响结果。

## js 中 >> 和 >>>  的区别

JavaScript 里这两个操作都先把数字转成 32-bit integer（32 位整数） 再移位，区别只在左边空出来的位填什么：

`>>` signed right shift（有符号右移）：左边填符号位 — 正数填 0，负数填 1。所以负数移完还是负数
`>>>` unsigned right shift（无符号右移，也叫 zero-fill right shift）：左边永远填 0。负数移完会变成一个很大的正数

-8 的 32 位表示: 11111111 11111111 11111111 11111000

-8 >> 2   左边填 1: 11111111 11111111 11111111 11111110  = -2
-8 >>> 2  左边填 0: 00111111 11111111 11111111 11111110  = 1073741822

-1 >>> 0  // 4294967295
是把任何数转成 uint32（无符号 32 位整数） 的惯用写法

## sets all bits after the lowest set bit to 1

```js
    x = x ^ x-1;

x = 12 -> 1100
x-1 = 11 -> 1011
x ^ (x-1) = 1100 ^ 1011 = 0111
```

## Removes the lowest set bit (rightmost 1) in i

```js
i & (i - 1)


i = 12  -> 1100
i-1 = 11 -> 1011
i & (i-1) = 1100 & 1011 = 1000
```

  1. Counting Bits

应用1:把一个整数用二进制表示时,其中二进制1的个数;

```js
  int count = 0;
  while(x)
  {
    x = x & (x - 1);
    count++;
  }
  return count;
```

应用2:判断一个整数(x)是否是2的n次方; If the result is 0, x had only one 1 bit, it means x is power of 2.

```js
  if((x & (x - 1)) == 0)
```

## Find the different bits

```ts
let diff = start ^ goal;
```

- 1. Minimum Bit Flips to Convert Number

## Flip a bit: 1 to 0 or 0 to 1

```ts
nums[i] ^= 1;
```

- 1. Maximum Height of a Triangle: switch color between red and blue

## Cancel the number

```ts
for (let i = 0; i < arrayLength; ++i) {
  // XOR the current index with the current array element and the current result.
  // This will cancel out all numbers from 0 to n except the missing one.
  result ^= i ^ nums[i];
}
```

- 1. Single Number
- 1. Missing Number
