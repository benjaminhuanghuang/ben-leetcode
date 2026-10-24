public class Solution088 {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        var i1 = m - 1;
        var i2 = n - 1;
        while (i1 >= 0 || i2 >= 0)
        {
            var a = i1 >= 0 ? nums1[i1] : int.MinValue;
            var b = i2 >= 0 ? nums2[i2] : int.MinValue;

            if (a > b)
            {
                nums1[i1 + i2 + 1] = a;
                i1 --;
            }
            else
            {
                nums1[i1 + i2 + 1] = b;
                i2--;
            }
        }
    }
}