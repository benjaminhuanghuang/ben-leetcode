/*
1603. Design Parking System

https://leetcode.com/problems/design-parking-system/
*/

class ParkingSystem {
  spaces: number[];
  constructor(big: number, medium: number, small: number) {
    this.spaces = [big, medium, small];
  }

  addCar(carType: number): boolean {
    if (this.spaces[carType - 1] > 0) {
      this.spaces[carType - 1]--;
      return true;
    }
    return false;
  }
}
