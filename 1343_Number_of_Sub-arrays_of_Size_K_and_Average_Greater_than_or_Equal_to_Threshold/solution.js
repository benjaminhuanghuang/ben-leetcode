/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Level: Medium

https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
*/

/*
  Solution: 
*/

/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} threshold
 * @return {number}
 */
var numOfSubarrays = function(arr, k, threshold) {
    var subArrSum = 0;
    // use var i here, because  i will be used in whill loop
    for(let i=0; i< k; i++)
    {
      subArrSum +=arr[i];
    }
    let res =0;
    // i = k
    while( i<arr.length){
      if(subArrSum/k >= threshold){
        res++;
      }
      subArrSum += arr[i];
      subArrSum -= arr[i-k];
      i++;
    }
    if(subArrSum /k >=threshold)
    {
      res++;
    }
    return res;
};


export { numOfSubarrays };