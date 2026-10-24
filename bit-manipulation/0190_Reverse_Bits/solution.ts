/*
190. Reverse Bits
*/

function reverseBits(n: number): number {
  let result: number = 0;

  // Loop through all 32 bits of the integer
  for (let i = 0; i < 32 && n > 0; ++i) {
    // Extract the least significant bit of 'n' and shift it to the correct position,
    // then OR it with the result to put it in its reversed position.
    result |= (n & 1) << (31 - i);

    // Logical shift the bits of 'n' right by 1, to process the next bit in the next iteration.
    n >>>= 1;
  }

  // The >>> 0 ensures the result is an unsigned 32-bit integer.
  return result >>> 0;
}

/*
https://stackoverflow.com/questions/4081216/what-does-x-0-do

x >>> 0 performs a logical (unsigned) right-shift of 0 bits, which is equivalent to a no-op. 
However, before the right shift, it must convert the x to an unsigned 32-bit integer. 
Therefore, the overall effect of x >>> 0 is convert x into a 32-bit unsigned integer.

js> (-4) >>> 0
4294967292
*/
