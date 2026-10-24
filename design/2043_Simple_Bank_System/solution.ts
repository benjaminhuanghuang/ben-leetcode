/*
2043. Simple Bank System

https://leetcode.com/problems/simple-bank-system/
*/

class Bank {
  // The balance for each account.
  bankBalance: number[];
  constructor(balance: number[]) {
    this.bankBalance = balance;
  }

  transfer(account1: number, account2: number, money: number): boolean {
    // Check for valid account numbers and sufficient balance in the source account.
    if (
      account1 > this.bankBalance.length ||
      account2 > this.bankBalance.length ||
      money > this.bankBalance[account1 - 1]
    )
      return false;

    // Perform the transfer.
    this.bankBalance[account1 - 1] -= money;
    this.bankBalance[account2 - 1] += money;
    return true;
  }

  deposit(account: number, money: number): boolean {
    // Check for a valid account number.
    if (account > this.bankBalance.length) return false;

    // Perform the deposit.
    this.bankBalance[account - 1] += money;
    return true;
  }

  withdraw(account: number, money: number): boolean {
    // Check for valid account numbers and sufficient balance.
    if (
      account > this.bankBalance.length ||
      money > this.bankBalance[account - 1]
    ) {
      return false;
    }

    // Perform the withdrawal.
    this.bankBalance[account - 1] -= money;
    return true;
  }
}
