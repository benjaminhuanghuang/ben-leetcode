public class Solution365 {
    //https://www.hrwhisper.me/leetcode-water-jug-problem/
    //问题其实可以转换为有一个很大的容器，有两个杯子，容量分别为x和y，问我们通过用两个杯子往里倒水，和往出舀水，问能不能使容器中的水刚好为z升
    //可以用一个公式来表达： z = m * x + n * y 若m,n>0说明往里面加水，若m,n <0则说明舀水
    public bool CanMeasureWater(int x, int y, int z) {
        return z == 0 || ((x + y >= z) &&z % gcd(x, y) == 0);
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
}