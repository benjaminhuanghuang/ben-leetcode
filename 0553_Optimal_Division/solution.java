package cn.huang.leetcode;
/*

553. Optimal Division
Given a list of positive integers, the adjacent integers will perform the float division.
    For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations.
You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string
format. Your expression should NOT contain redundant parenthesis.

 */
public class LC_0553_OptimalDivision {
    /*
    最大的情况一直都是A[0] / ( A[1] / A[2] / ... / A[N-1] )
     */
    public String optimalDivision(int[] nums) {
        String s="";
        if(nums.length==1){
            return s+nums[0];
        }
        if(nums.length==2){
            return s+nums[0]+"/"+nums[1];
        }

        s+=nums[0]+"/(";
        s+=nums[1];
        for(int i=2;i<nums.length;i++){
            s+="/"+nums[i];
        }
        s+=")";
        return s;
    }
}
