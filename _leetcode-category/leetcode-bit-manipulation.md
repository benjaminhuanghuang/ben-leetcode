# Bit Manipulation

## Shift
- C++

  "<<" shifts left and adds zeros at the right end.

  ">>" shifts right and adds either 0s, if value is an unsigned type, or extends the top bit (to preserve the sign) if its a signed type. In other words, if the number is positive, 0 is used, and if the number is negative, 1 is used.

- Java

  The signed left shift operator "<<" shifts a bit pattern to the left

  The signed right shift operator ">>" shifts a bit pattern to the right.

  The unsigned right shift operator ">>>" shifts a zero into the leftmost position

- C#

  Same as C++

- Python

  Same as C++

- JavaScript / TypeScript

  Same as java

  https://www.w3schools.com/js/js_bitwise.asp

- Go

  Same as C++

## Code snippets
- Set 1 bit to 1 or 0
```
  if ((t & (1 << i)) == 0)
    t |= (1 << i);   // i 位变成 1
  else
    t &= ~(1 << i);  // i 位变成 0
```
From #89. Gray code

- Upper case <-> lower case
upper case 'A' 1000001 41H(65) 
lower case 'a' 1100001 61H(97), 
```
  c ^= (1 << 5);
```
## 操作符优先级
```
 cur = (cur << 1) + a;
```  
  
## Problems
- 190. Reverse Bits

- 1018. Binary Prefix Divisible By 5




