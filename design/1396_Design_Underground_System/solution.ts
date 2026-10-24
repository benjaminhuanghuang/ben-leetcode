/*
1396. Design Underground System

https://leetcode.com/problems/design-underground-system/
*/

class UndergroundSystem {
  private checkIns: { [id: number]: { t: number; stationName: string } };
  private trips: { [route: string]: number[] };

  constructor() {
    this.checkIns = {};
    this.trips = {};
  }

  checkIn(id: number, stationName: string, t: number): void {
    this.checkIns[id] = {
      t: t,
      stationName: stationName,
    };
  }

  checkOut(id: number, stationName: string, t: number): void {
    const route = `${this.checkIns[id].stationName}=>${stationName}`;
    if (!(route in this.trips)) {
      this.trips[route] = [];
    }
    this.trips[route].push(t - this.checkIns[id].t);
    delete this.checkIns[id]; // Optionally clean up after checkout
  }

  getAverageTime(startStation: string, endStation: string): number {
    const route = `${startStation}=>${endStation}`;
    const times = this.trips[route];
    const sum = times.reduce((acc, time) => acc + time, 0);
    return sum / times.length;
  }
}
