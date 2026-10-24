using System.Linq;
using System.Collections.Generic;

public class Solution217 {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> s = new HashSet<int>(nums);
        return nums.Length > s.Count; 
    }

    public bool ContainsDuplicate_2(int[] nums)
    {
        return nums.Length > nums.Distinct().Count();
    }
}