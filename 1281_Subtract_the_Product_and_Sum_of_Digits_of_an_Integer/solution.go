// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
package leetcode1281
/*
	
 */

func subtractProductAndSum(n int) int {
		product:=-1
		sum:=0

		for n > 0{
			digit := n %10
			if product == -1{
				product = digit
			}else{
				product *= digit
			}
			sum += digit

			n = n /10
		}

		return product - sum
}