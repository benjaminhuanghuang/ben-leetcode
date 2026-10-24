using System; 
public class Solution223 {
    public int ComputeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) 
            return sum;
        return sum - ((Math.Min(G, C) - Math.Max(A, E)) * (Math.Min(D, H) - Math.Max(B, F)));
    }
}