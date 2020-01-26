/*
260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements 
appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space 
complexity?

*/
// http://fisherlei.blogspot.com/2015/10/leetcode-single-number-iii-solution.html
public class Solution260 {
    public int[] SingleNumber(int[] nums) {
        int A = 0;  
        int B = 0;  
        int AXORB = 0;  
        // 因为其他的数因为出现了两次，异或的过程中就被清零了。
        for(int i = 0; i<nums.Length; i++){  
            AXORB ^= nums[i];  
        }  
        // 对于A和B，除非两者是相同的数，否则一定存在第K位bit是不同的.
        // 当找到这个K以后，就可以按照第K位bit是否等于1，将A数组划分成两个子数组，而这两个子数组分别包含了b和c，
        // 那么剩下的就只需要把single number的算法直接应用到这两个子数组上，就可以得到b和c了。
       
        AXORB = AXORB & (~(AXORB - 1)); 
        // a_xor_b &= -a_xor_b  # Get the last set (1) bit, that is the last difference bit those two number have
        
        for(int i = 0; i<nums.Length; i++){  
            if((AXORB & nums[i]) == 0)  
                A ^= nums[i];  
            else  
                B ^= nums[i];  
        }  
        return new int[]{A, B};  
    }

    // // http://fisherlei.blogspot.com/2015/10/leetcode-single-number-iii-solution.html
    public int[] SingleNumber_2(int[] nums) {
        int A = 0;  
        int B = 0;  
        int AXORB = 0;  
        // 因为其他的数因为出现了两次，异或的过程中就被清零了。
        for(int i = 0; i<nums.Length; i++){  
            AXORB ^= nums[i];  
        }  
        // 对于A和B，除非两者是相同的数，否则一定存在第K位bit是不同的.
        // 当找到这个K以后，就可以按照第K位bit是否等于1，将A数组划分成两个子数组，而这两个子数组分别包含了b和c，
        // 那么剩下的就只需要把single number的算法直接应用到这两个子数组上，就可以得到b和c了。
        AXORB = (AXORB & (AXORB - 1)) ^ AXORB; //find the different bit  
        // a_xor_b &= -a_xor_b  # Get the last set (1) bit, that is the last difference bit those two number have
        
        for(int i = 0; i<nums.Length; i++){  
            if((AXORB & nums[i]) == 0)  
                A ^= nums[i];  
            else  
                B ^= nums[i];  
        }  
        return new int[]{A, B};  
    }
}