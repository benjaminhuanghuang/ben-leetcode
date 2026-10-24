using System;
public class Solution326 {
    public bool IsPowerOfThree(int n) {
        return n <= 0 ? false : n == Math.Pow(3, Math.Round(Math.Log(n) / Math.Log(3)));
    }

    bool isPowerOfThree(int n) {
		if (n <= 0) return false;
		if (n == 1) return true;
		return n % 3 == 0 && isPowerOfThree(n / 3);
	}
}