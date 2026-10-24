/*
1656. Design an Ordered Stream

https://leetcode.com/problems/design-an-ordered-stream/
*/

class OrderedStream {
  // A global pointer for the current position in the stream.
  ptr: number = 0;
  // A global array to store the values in the stream.
  vals: string[];

  constructor(n: number) {
    this.ptr = 0;
    this.vals = new Array(n);
  }

  insert(idKey: number, value: string): string[] {
    // Adjust the idKey from a 1-based to a 0-based index.
    const index = idKey - 1;
    this.vals[index] = value;

    // Create an array to hold the results.
    const result: string[] = [];

    // Add all contiguous non-null values starting from the current pointer position.
    while (this.vals[this.ptr] != null) {
      result.push(this.vals[this.ptr]);
      this.ptr++;
    }

    // Return the contiguous values found.
    return result;
  }
}
