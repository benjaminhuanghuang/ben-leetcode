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
