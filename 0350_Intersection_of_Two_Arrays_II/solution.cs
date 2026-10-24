using System;

public class Solution350
{
  public int[] Intersect(int[] nums1, int[] nums2)
  {
    Array.Sort(nums1);
    Array.Sort(nums2);

    int i = 0, j = 0;
    List<int> intersection = new List<int>();
    while (i < nums1.Length && j < nums2.Length)
    {
      if (nums1[i] == nums2[j])
      {
        intersection.Add(nums1[i]);
        i++;
        j++;
      }
      else if (nums1[i] < nums2[j])
      {
        i++;
      }
      else
      {
        j++;
      }
    }

    int[] result =  intersection.ToArray();;

    return result;
  }
}