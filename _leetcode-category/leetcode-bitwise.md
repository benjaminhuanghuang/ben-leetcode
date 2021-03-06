# Bit Manipulation

## Shift
### C++

  "<<" shifts left and adds zeros at the right end.

  ">>" shifts right and adds either 0s, if value is an unsigned type, or extends the top bit (to preserve the sign) if its a signed type. In other words, if the number is positive, 0 is used, and if the number is negative, 1 is used.

### Java

  The signed left shift operator "<<" shifts a bit pattern to the left

  The signed right shift operator ">>" shifts a bit pattern to the right.

  The unsigned right shift operator ">>>" shifts a zero into the leftmost position

### C#

  Same as C++

### Python

  Same as C++

### JavaScript / TypeScript

  Same as java

  https://www.w3schools.com/js/js_bitwise.asp

### Go

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
- 201. Bitwise AND of Numbers Range
- 260. Single Number III                 # group 
- 318. Maximum Product of Word Lengths   # & check common charactor
- 338. Counting Bits
- 393. UTF-8 Validation
- 405. Convert a Number to Hexadecimal
- 421. Maximum XOR of Two Numbers in an Array    # a^b = c, a^c = b，b^c = a;
- 461. Hamming Distance                  # a ^ b 基本概念
- 476. Number Complement                 # Complement with mask, be careful the overflow
- 1009. Complement of Base 10 Integer
- 1017. Convert to Base -2
- 1018. Binary Prefix Divisible By 5
- 1104. Path In Zigzag Labelled Binary Tree
- 1310. XOR Queries of a Subarray                               # prefix
- 1404. Number of Steps to Reduce a Number in Binary Representation to One
- 1442. Count Triplets That Can Form Two Arrays of Equal XOR    # O(N^4) -> O(N)


### Meth operation
- 371. Sum of Two Integers           # binary 


### Power 
- 231. Power of Two       # count 1
- 326. Power of Three     # n % 3
- 342. Power of Four      # 0x55555555 

