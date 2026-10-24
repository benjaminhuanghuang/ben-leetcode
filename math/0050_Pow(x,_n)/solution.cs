/*
50. Pow(x, n)
Implement pow(x, n).
*/


public class Solution050 {
    public double MyPow(double x, int n) {
        if (n>=0)
            return this.PowerHelper(x, n);
        else
            return 1/ this.PowerHelper(x, -n);
    }

    // x^n = x^(n/2)*x^(n/2)*x^(n%2)
    private double PowerHelper(double x, int n)
    {
        if (n ==0)
            return 1;
        double res = this.PowerHelper(x, n /2);
        res *= res;
        if (n % 2 != 0)
        {
            res *= x;
        }
        return res;
    }
}