/*
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

using System.Collections.Generic;

public class MedianFinder {
    private List<double> values = new List<double>();
    // Adds a num into the data structure.
    public void AddNum(double num) {
        if(values.Count == 0)
        {
            values.Add(num);
            return;
        }

        if(num < values[0])
        {
            values.Insert(0, num);
            return;
        }

        if(num >= values[values.Count - 1])
        {
             values.Add(num);
             return;
        }   
        int l =0;
        int r = values.Count - 1;
        while (l < r)
        {
            int m = l + (r-l)/2;
            if (values[m] > num)
                r = m;
            else
                l = m + 1;
        }
        values.Insert(l, num);
    }

    // return the median of current data stream
    public double FindMedian() {
        if (values.Count ==0)
            return 0;
        int mid = values.Count / 2;
        if (values.Count % 2 == 0)
        {
            return (values[mid - 1] + values[mid]) / 2;
        }
        else    
            return values[mid];
    }
}
