/*
2526. Find Consecutive Integers from a Data Stream

https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
*/

class DataStream {
  currentValue: number;
  threshold: number;
  consecutiveCount: number;

  constructor(value: number, k: number) {
    this.currentValue = value;
    this.threshold = k;
    this.consecutiveCount = 0;
  }
  /*
    Returns true if the last k integers are equal to value, 
    */
  consec(num: number): boolean {
    if (this.currentValue === num) {
      this.consecutiveCount += 1;
    } else {
      this.consecutiveCount = 0;
    }

    return this.consecutiveCount >= this.threshold;
  }
}
