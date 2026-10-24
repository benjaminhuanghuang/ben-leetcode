using System;

public class Solution165 {
    public int CompareVersion(string version1, string version2) {
        string[] v1= version1.Split('.');
        string[] v2= version2.Split('.');

        for (int i = 0; i < Math.Max(v1.Length, v2.Length); i++)
        {
            var num1 = int.Parse(i < v1.Length ? v1[i] : "0");
            var num2 = int.Parse(i < v2.Length ? v2[i] : "0");

            if (num1 < num2)                 
            {                     
                return -1;                 
            }                 
            if (num1 > num2)
            {
                return 1;
            }
        }

        return 0;
    }
}