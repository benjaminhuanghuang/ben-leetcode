/*
1357. Apply Discount Every n Orders

Level: Medium

https://leetcode.com/problems/apply-discount-every-n-orders
*/

/*
  Solution: 
  https://www.youtube.com/watch?v=MZ3oKJb_6C0
*/

/**
 * @param {number} n
 * @param {number} discount
 * @param {number[]} products
 * @param {number[]} prices
 */
var Cashier = function (n, discount, products, prices) {
  this.discount = 1 - discount / 100;
  this.products = {};
  products.forEach((p, idx) => {
    this.products[p] = products[idx];
  });
  this.customer = 0;
};

/**
 * @param {number[]} product
 * @param {number[]} amount
 * @return {number}
 */
Cashier.prototype.getBill = function (product, amount) {
  this.customer++;
  var factor = 1;
  if (this.customer % this.n === 0) {
    factor = this.discount;
  }
  const res = product.reduce((total, curr, idx) => {
    return total + this.products[curr] * amount[idx] * factor;
  }, 0);
  return res;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * var obj = new Cashier(n, discount, products, prices)
 * var param_1 = obj.getBill(product,amount)
 */

export { twoSum };
