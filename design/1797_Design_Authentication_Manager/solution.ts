/*
1797. Design Authentication Manager

https://leetcode.com/problems/design-authentication-manager/
*/

class AuthenticationManager {
  timeToLive: number;
  tokenMap: Map<string, number> = new Map(); // Map to store the token and its expiry time.
  constructor(timeToLive: number) {
    this.timeToLive = timeToLive;
  }

  generate(tokenId: string, currentTime: number): void {
    this.tokenMap.set(tokenId, currentTime + this.timeToLive);
  }

  renew(tokenId: string, currentTime: number): void {
    const expirationTime = this.tokenMap.get(tokenId);
    if (expirationTime && expirationTime > currentTime) {
      this.tokenMap.set(tokenId, currentTime + this.timeToLive);
    }
  }

  countUnexpiredTokens(currentTime: number): number {
    let count = 0;
    this.tokenMap.forEach((expirationTime) => {
      if (expirationTime > currentTime) {
        count++;
      }
    });
    return count;
  }
}
