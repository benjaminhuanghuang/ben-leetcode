public class Solution167 {
    public int[] TwoSum(int[] numbers, int target) {
        for (int i = 0, j = numbers.Length-1; i < j;)
        {
            if (numbers[i] + numbers[j] == target)
            {
                return new int[]{i+1, j+1};
            }
            else if(numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return new int[]{-1, -1};
    }
}