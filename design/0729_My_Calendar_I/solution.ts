/*
729. My Calendar I

https://leetcode.com/problems/my-calendar-i/


- 715 Range Module https://www.youtube.com/watch?v=pcpB9ux3RrQ
- 699. Falling Squares https://www.youtube.com/watch?v=UeuV-6Ygxs4
- 56. Merge Intervals https://www.youtube.com/watch?v=6tLHjei-f0I
- 57. Insert Interval https://www.youtube.com/watch?v=oWHWDI2eOHY
*/

/*
https://www.youtube.com/watch?v=seQnf-5hlBo&t=1s

*/
class MyCalendar {
  events: [number, number][];

  constructor() {
    this.events = [];
  }

  book(start: number, end: number): boolean {
    for (const [s, e] of this.events) {
      if (s < end && start < e) {
        return false;
      }
    }
    this.events.push([start, end]);
    return true;
  }
}
