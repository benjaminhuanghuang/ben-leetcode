/*
  Solution: split on "." and ":" and validate each candidate format
  independently; whichever one matches wins, otherwise "Neither".
*/

/**
 * @param {string} IP
 * @return {string}
 */
var validIPAddress = function (IP) {
  if (validIPv4(IP)) {
    return "IPv4";
  }
  if (validIPv6(IP)) {
    return "IPv6";
  }
  return "Neither";
};

function validIPv4(IP) {
  const parts = IP.split(".");
  if (parts.length !== 4) {
    return false;
  }
  for (const part of parts) {
    if (!part || !/^\d+$/.test(part)) {
      return false;
    }
    if (part.length > 1 && part[0] === "0") {
      return false;
    }
    const num = parseInt(part, 10);
    if (isNaN(num) || num < 0 || num > 255) {
      return false;
    }
  }
  return true;
}

function validIPv6(IP) {
  const parts = IP.split(":");
  if (parts.length !== 8) {
    return false;
  }
  for (const part of parts) {
    if (!part || part.length > 4 || !/^[0-9a-fA-F]+$/.test(part)) {
      return false;
    }
  }
  return true;
}

export { validIPAddress };
