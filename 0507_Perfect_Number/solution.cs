public class Solution507
{
    public bool CheckPerfectNumber(int num)
    {
        int total = 1;
        int div = 2;
        while (div * div <= num)
        {
            if ((num % div) == 0)
            {
                total += div;
                if (div * div != num)
                    total += num / div;
            }
            div++;
        }
        return num > 1 && total == num;
    }
}