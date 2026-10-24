/*
468. Validate IP Address

https://leetcode.com/problems/validate-ip-address/

[Google]
*/

/*

*/
function validIPAddress(IP: string): string {
  if (validIPv4(IP)) {
    return "IPv4";
  }
  if (validIPv6(IP)) {
    return "IPv6";
  }
  return "Neither";
}

function validIPv4(IP: string): boolean {
  const parts = IP.split(".");
  if (parts.length !== 4) {
    return false;
  }
  for (const part of parts) {
    if (!part || !part.match(/^\d+$/)) {
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

function validIPv6(IP: string): boolean {
  const parts = IP.split(":");
  if (parts.length !== 8) {
    return false;
  }
  for (const part of parts) {
    if (!part || part.length > 4 || !part.match(/^[0-9a-fA-F]+$/)) {
      return false;
    }
  }
  return true;
}
