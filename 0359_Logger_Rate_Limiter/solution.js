/*
  Solution: keep a hash map from message to the timestamp it was last
  printed. A message prints if it has never been seen, or if at least
  10 seconds have passed since it last printed; either way the map is
  updated to the new timestamp.
*/

var Logger = function () {
  this.lastPrinted = new Map();
};

/**
 * @param {number} timestamp
 * @param {string} message
 * @return {boolean}
 */
Logger.prototype.shouldPrintMessage = function (timestamp, message) {
  const last = this.lastPrinted.get(message);
  if (last === undefined || timestamp - last >= 10) {
    this.lastPrinted.set(message, timestamp);
    return true;
  }
  return false;
};

/**
 * Your Logger object will be instantiated and called as such:
 * var obj = new Logger()
 * var param_1 = obj.shouldPrintMessage(timestamp,message)
 */

export { Logger };
