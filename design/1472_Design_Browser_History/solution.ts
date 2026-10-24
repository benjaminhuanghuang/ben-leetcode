/*
1472. Design Browser History

https://leetcode.com/problems/design-browser-history/
*/

class BrowserHistory {
  backHistory: string[] = []; // Array to manage back navigation.
  forwardHistory: string[] = []; // Array to manage forward navigation.

  constructor(homepage: string) {
    this.visit(homepage); // Visit the initial page.
  }

  visit(url: string): void {
    this.backHistory.push(url);
    this.forwardHistory = []; // Clear the forward history since we visited a new URL.
  }

  back(steps: number): string {
    // Go back at most 'steps' times and make sure not to go past the initial page.
    while (steps > 0 && this.backHistory.length > 1) {
      this.forwardHistory.push(this.backHistory.pop()!); // Assert non-null as we know there's more than one item.
      steps--;
    }
    return this.backHistory[this.backHistory.length - 1]; // Return the current URL.
  }

  forward(steps: number): string {
    // Go forward at most 'steps' times and only if there is forward history available.
    while (steps > 0 && this.forwardHistory.length > 0) {
      this.backHistory.push(this.forwardHistory.pop()!); // Assert non-null as the length check ensures the item exists.
      steps--;
    }
    return this.backHistory[this.backHistory.length - 1]; // Return the current URL.
  }
}
