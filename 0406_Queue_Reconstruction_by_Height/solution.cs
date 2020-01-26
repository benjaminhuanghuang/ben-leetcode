/*
406. Queue Reconstruction by Height

Suppose you have a random list of people standing in a queue. Each person is described by a pair of 
integers (h, k), where h is the height of the person and k is the number of people in front of this 
person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//整数(h, k)描述，其中h是其身高，k是站在他前面并且身高不低于他的人数

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
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
