/*
855. Exam Room

https://leetcode.com/problems/exam-room/
*/

/*
https://www.youtube.com/watch?v=-dGB1j3Pk18

*/
class ExamRoom {
  private seats: number[]; // use a linked list for leave() operation
  private start: number;
  private end: number;

  constructor(n: number) {
    this.end = n - 1;
    this.start = 0;
    this.seats = [];
  }

  seat(): number {
    // If no one is seated, seat the first student at the start
    if (this.seats.length === 0) {
      this.seats.push(this.start);
      return this.start;
    }

    let maxDistance = 0; // used to find the max distance between two seats
    let pick = -1; // The seat number to pick
    let index = -1; // The index to insert the seat number in this.seats

    // If the first seat #0 is empty, check if #0 is the best seat
    if (this.seats[0] !== 0) {
      pick = 0;
      maxDistance = this.seats[0];
      index = 0;
    }

    let l = 0,
      r = 0;
    for (let i = 0; i < this.seats.length; i++) {
      if (i === 0) {
        l = this.seats[0];
        continue;
      } else {
        l = r;
      }
      r = this.seats[i];
      let mid = Math.floor((l + r) / 2);
      let dt = mid - l;
      if (dt > maxDistance) {
        maxDistance = dt;
        pick = mid;
        index = i;
      }
    }

    if (this.seats[this.seats.length - 1] < this.end) {
      l = this.seats[this.seats.length - 1];
      r = this.end;
      let dt = r - l;
      if (dt > maxDistance) {
        maxDistance = dt;
        pick = r;
        index = this.seats.length;
      }
    }

    this.seats.splice(index, 0, pick);
    return pick;
  }

  // p is the seat number
  leave(p: number): void {
    const index = this.seats.indexOf(p);
    if (index !== -1) {
      this.seats.splice(index, 1);
    }
  }
}

/*
    Ordered Set
*/
