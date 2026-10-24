/*
401. Binary Watch

https://leetcode.com/problems/binary-watch/
*/

function readBinaryWatch(num: number): string[] {
  const result: string[] = [];
  const hours: number[] = [8, 4, 2, 1];
  const minutes: number[] = [32, 16, 8, 4, 2, 1];

  // num: the number of LEDs to be turned on
  // start: the index to start from
  function backtrack(
    num: number,
    start: number,
    hour: number,
    minute: number
  ): void {
    if (hour > 11 || minute > 59) return; // Invalid time
    if (num === 0) {
      result.push(`${hour}:${minute < 10 ? "0" : ""}${minute}`);
      return;
    }

    for (let i = start; i < hours.length + minutes.length; i++) {
      if (i < hours.length) {
        // Pick an hour LED
        backtrack(num - 1, i + 1, hour + hours[i], minute);
      } else {
        // Pick a minute LED
        backtrack(num - 1, i + 1, hour, minute + minutes[i - hours.length]);
      }
    }
  }

  backtrack(num, 0, 0, 0);
  return result;
}
