using System.Collections.Generic;

public class Solution447 {
    class Point{
        public int X {get; set;}
        public int Y {get; set;}

        public long Distance(Point other)
        {
            return (X- other.X)*(X- other.X) + (Y- other.Y)*(Y- other.Y); 
        }
    }
    //http://bookshadow.com/weblog/2016/11/06/leetcode-number-of-boomerangs/
    public int NumberOfBoomerangs(int[,] points) {
        List<Point> pList = new List<Point>();
        for(int i = 0; i < points.GetLength(0); i++)
        {
            pList.Add(new Point(){X= points[i,0], Y = points[i,1]});
        }
        int ans = 0;
        var dict = new Dictionary<long, int>();
        foreach( var p1 in pList)
        {
            dict.Clear();
            foreach (var p2 in pList)
            {
                if (p2.X != p1.X || p2.Y != p1.Y)
                {
                    long distance = p1.Distance(p2);
                    if (dict.ContainsKey(distance))
                        dict[distance]++;
                    else 
                        dict.Add(distance, 1);
                }
            }

            foreach (var kv in dict)
            {
                ans += kv.Value * (kv.Value -1);
            }
        }
        return ans;
    }
}