/*
2433. Find The Original Array of Prefix Xor

https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
*/

/*
    pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
    pref[0] = arr[0]
    pref[1] = arr[0] ^ arr[1] = pref[0] ^ arr[1]
    pref[2] = arr[0] ^ arr[1] ^ arr[2] = pref[1] ^ arr[2]
    
    ...
    arr[i] = pref[i] ^ pref[i-1] 
*/
function findArray(pref: number[]): number[] {
  let answer = [...pref];

  for (let i = 1; i < pref.length; i++) {
    answer[i] = pref[i - 1] ^ pref[i];
  }

  return answer;
}
