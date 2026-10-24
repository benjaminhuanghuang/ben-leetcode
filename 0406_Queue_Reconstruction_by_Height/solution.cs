using System;
using System.Collections.Generic;

public class Solution406 {
    //https://discuss.leetcode.com/topic/62777/c-solution
    public int[,] ReconstructQueue(int[,] people) {
        List<Tuple<int, int>> temp = new List<Tuple<int, int>>();
        for (int i = 0; i < people.GetLength(0); i++)
        {
            temp.Add(new Tuple<int, int>(people[i, 0], people[i, 1]));
        }
        // sort the numbers first by height and then by the position. 
        // height in "descending" order and position in "ascending" order.
        temp.Sort((x, y) => { int result = y.Item1.CompareTo(x.Item1); return result == 0 ? x.Item2.CompareTo(y.Item2) : result; });
        
        List<Tuple<int, int>> temp2 = new List<Tuple<int, int>>();
        for (int i = 0; i < temp.Count; i++)
        {
            // temp[i].Item2 is position
            temp2.Insert(temp[i].Item2, temp[i]);
        }

        //place the result back in original 2d array
        for (int l = 0; l < people.GetLength(0); l++)
        {
            people[l, 0] = temp2[l].Item1;
            people[l, 1] = temp2[l].Item2;
        }
        return people;
    }
}
