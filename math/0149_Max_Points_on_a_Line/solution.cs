/*
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
using System;
using System.Linq;
using System.Collections.Generic;

// Definition for a point.
public class Point {
     public int x;
     public int y;
     public Point() { x = 0; y = 0; }
     public Point(int a, int b) { x = a; y = b; }
}

public class Solution149 {
    // for each point, calculate the slope with other point. put slope into hash table, then we know points with same slope in a line.
    // points with same x and y. in that case, slope does not work. use an int to count how many points are same.
    public int MaxPoints(Point[] points) {
        var max = 0;
        foreach (var point in points)
        {
            var hashtable = new Dictionary<double, int>();
            var samePointNumber = 0;
            foreach (var anotherPoint in points)
            {
                // Skip the point has same location
                if (point.x == anotherPoint.x && point.y == anotherPoint.y)
                {
                    samePointNumber++;
                    continue;
                }
                // Count points has same slop
                var slop = (point.y - anotherPoint.y) * 1.0 / (point.x - anotherPoint.x);
                if (hashtable.ContainsKey(slop))
                {
                    hashtable[slop]++;
                }
                else
                {
                    hashtable.Add(slop, 1);
                }
            }
            //max = Math.Max(max, Math.Max(hashtable.values()) + samePointNumber)
            max = Math.Max(max, samePointNumber);
            max = hashtable.Values.Select(value => value + samePointNumber).Concat(new[] { max }).Max();
        }

        return max;
    }
}