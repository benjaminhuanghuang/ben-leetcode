/*
2241. Design an ATM Machine

https://leetcode.com/problems/design-an-atm-machine/
*/

class ATM {
  banknoteCounters: Array<number> = [0, 0, 0, 0, 0];
  denominations: Array<number> = [20, 50, 100, 200, 500];

  constructor() {}

  deposit(banknotesCount: number[]): void {
    for (let i = 0; i < banknotesCount.length; i++) {
      this.banknoteCounters[i] += banknotesCount[i];
    }
  }

  withdraw(amount: number): number[] {
    let result = [0, 0, 0, 0, 0]; // Stores the number of banknotes to dispense for each denomination

    // Iterate from highest denomination to lowest
    for (let i = 4; i >= 0; i--) {
      let numBanknotes = Math.min(
        Math.floor(amount / this.denominations[i]),
        this.banknoteCounters[i]
      );
      amount -= numBanknotes * this.denominations[i];
      result[i] = numBanknotes;
    }

    // Check if the full amount could be withdrawn
    if (amount > 0) {
      // Failure to withdraw the full amount
      return [-1];
    }

    // Subtract the dispensed banknotes from the banknote counters
    for (let i = 0; i < 5; i++) {
      this.banknoteCounters[i] -= result[i];
    }

    // Return the number of banknotes dispensed for each denomination
    return result;
  }
}
