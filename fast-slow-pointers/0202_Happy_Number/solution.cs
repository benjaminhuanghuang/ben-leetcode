using System.Collections.Generic;

public class Solution202 {
    public bool IsHappy(int n) {
        var visited = new Dictionary<int, bool>();
        var next = n;

        while (!visited.ContainsKey(next))
        {
            visited.Add(next, true);
            var start = next;
            next = 0;

            while (start != 0)
            {   
                int digit = start % 10;
                next += digit * digit;
                start /= 10;
            }

            if (next == 1) 
                return true;
        }

        return false;
    }
}