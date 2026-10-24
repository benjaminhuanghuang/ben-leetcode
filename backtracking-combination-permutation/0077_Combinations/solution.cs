using System;
using System.Collections.Generic;

public class Solution077 {
    public IList<IList<int>> Combine(int n, int k) {
        var res = new List<IList<int>>();
        
        Combine_Recursion(n, k, 1, new List<int>(), res);
        
        return res;
    }
    
    // pick item i and find k – 1 items in the rest of the numbers(>= i).
    private void Combine_Recursion(int n, int k, int cur, List<int> combination, IList<IList<int>> res)
    {
        if (0 == k)
        {
            res.Add(new List<int>(combination));
            return;
        }

        for (int i = cur; i <= n; i++)
        {
            combination.Add(i);
            // Combine_Recursion(n, k - 1, cur + 1, combination, res); <=causes error.
            Combine_Recursion(n, k - 1, i + 1, combination, res);
            combination.RemoveAt(combination.Count - 1);
        }
    }
    private void Combine_Recursion_Wrong(int n, int k, int cur, List<int> combination, IList<IList<int>> res)
    {
        if (k == 0)
        {
            res.Add(new List<int>(combination));
            return;
        }

        for (int i = cur; i <= n; i++)
        {
            combination.Add(i);
            Console.WriteLine(String.Join(", ", combination)); 
            Combine_Recursion(n, k - 1, cur + 1, combination, res);
            combination.RemoveAt(combination.Count - 1);
        }
    }

    // C(n,k)=C(n-1,k-1)+C(n-1,k): 
    // pick k from N = (pick k -1 from n – 1 then append n) + (pick k from n -1).
    public List<List<int>> Combine_Recursion(int n, int k)
    {
        var result = new List<List<int>>();
        if (n < k)
        {
            return result;
        }

        if (k == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                var temp = new List<int>(){i};
                result.Add(temp);
            }
            return result;
        }

        result = Combine_Recursion(n - 1, k - 1);
        foreach (var res in result)
        {
            res.Add(n);
        }

        result.AddRange(Combine_Recursion(n - 1, k));

        return result;
    }
}