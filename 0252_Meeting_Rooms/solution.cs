using System;
using System.Collections.Generic;

public class Solution252
{
  public class Interval
  {
    public int start;
    public int end;
  }

  public bool canAttendMeetings(Interval[] intervals)
  {
    // Error Cannot convert lambda expression to type 'Array' because it is not a delegate type
    // intervals.Sort((i1, i2) => i1.start - i2.start); 
    Array.Sort(intervals, (i1, i2) => i1.start - i2.start);

    for (int i = 0; i < intervals.Length - 1; i++)
    {
      if (intervals[i].end > intervals[i + 1].start)
      {
        return false;
      }
    }

    return true;
  }
}
