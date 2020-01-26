/*
551. Student Attendance Record I

You are given a string representing an attendance record for a student. The record only contains 
the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or 
more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
 */

public class Solution551
{
    public bool CheckRecord(string s)
    {
        if (s == null || s.Length == 0)
            return false;

        char[] charArr = s.ToCharArray();
        int countA = 0;
        int countL = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (charArr[i] == 'A')
            {
                if (countA == 0)
                    countA += 1;
                else
                    return false;
            }
            if (charArr[i] == 'L')
            {
                if (countL < 2)
                    countL += 1;
                else
                    return false;
            }
            else
                countL = 0;
        }

        return true;
    }
}