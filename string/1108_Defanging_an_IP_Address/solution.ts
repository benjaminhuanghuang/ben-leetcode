/*
Time complexity: O(n)
Space complexity: O(n)
*/
function defangIPaddr(address: string): string {
  return address.split(".").join("[.]");
}

export {};
