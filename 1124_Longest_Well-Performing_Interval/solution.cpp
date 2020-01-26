/*
1124. Longest Well-Performing Interval
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int maxLen = 0;
        int tiringDayStart = -1;
        int tiringDayEnd = -1;
        int normalDayStart = -1;
        int normalDayEnd = -1;
        for (int i = 0; i < hours.size(); i++)
        {
            if (hours[i] == 0)
            {
                if (tiringDayStart >= 0)
                    maxLen = max(maxLen, i - tiringDayStart);
                normalDayStart = -1;
                tiringDayStart = -1;
            }
            else if (hours[i] > 8)
            {
                if (tiringDayStart > tiringDayStart || tiringDayStart == -1)
                {
                    if (tiringDayStart >= 0)
                        maxLen = max(maxLen, i - tiringDayStart);
                    normalDayStart = i;
                    tiringDayStart = i;
                }
            }
            else
            {
                if (normalDayStart == tiringDayStart)
                {
                    normalDayStart = i;
                }
            }
        }
        if (hours[hours.size() - 1] > 0 && tiringDayStart > 0)
        {
            maxLen = max(maxLen, int(hours.size() - 1 - tiringDayStart));
        }
        return maxLen;
    }
};