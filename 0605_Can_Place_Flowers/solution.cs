public class Solution605
{
    public bool CanPlaceFlowers(int[] flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.Length; i++)
        {
            if (flowerbed[i] == 1)
                continue;
            // flowerbed[i] == 0
            if (i > 0 && flowerbed[i - 1] == 1)
                continue;
            if (i < flowerbed.Length - 1 && flowerbed[i + 1] == 1)
                continue;

            flowerbed[i] = 1;
            n--;
        }

        return n <= 0;
    }
}