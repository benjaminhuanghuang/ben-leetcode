/*
1352. Product of the Last K Numbers

Level: Medium

https://leetcode.com/problems/product-of-the-last-k-numbers
*/

/*
  Solution: 
  https://www.youtube.com/watch?v=V2smfTo58wI
*/


var ProductOfNumbers = function() {
    
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
   if(num===0){
     this.prods =[];
   } 
   else{
     if(this.props.length > 0 ){
       this.prods.push(nums * this.prods[this.prods.length-1]);
     }
     else
     {
       this.prods.push(num);
     }
   }
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
  const n = this.prods.length;
  if(k < n)
  {
    return this.props[n-1] / this.propds[n-1-k]
  }
  else if(k==n) {
    return this.prods[n-1];
  }
  return 0;
};

/** 
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */


export { twoSum };