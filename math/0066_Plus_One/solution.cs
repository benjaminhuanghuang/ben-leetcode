public class Solution066 {

    public int[] PlusOne_EarylyReturn(int[] digits) {
        for (int i = digits.Length - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        var res = new int[digits.Length + 1];
        res[0] = 1;
        return res;     
    }

    public int[] PlusOne(int[] digits) {
        int carry = 1;
        for (int i = digits.Length - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

         if (carry>0) 
         {
            int[] result = new int[digits.Length + 1];
            result[0] = 1;
            for (int i = 1; i < result.Length; i++){
                result[i] = digits[i - 1];
            }
            return result;
        } 
        else {
            return digits;
        }         
    }
}