/*
401. Binary Watch
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom 
represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

0011
011001
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all 
possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, 
it should be "10:02".
*/

using System.Collections.Generic;

public class Solution401 {
    //10 LED can present 0 to 1024
    public IList<string> ReadBinaryWatch(int num) {
        List<string> result = new List<string>();
        for (int i = 0 ;i < 1024; i++)
        {
            if(this.countDigits(i) == num)
            {
                string time =  this.ParseTime(i);
                if(time.Length > 0)
                    result.Add(this.ParseTime(i));
            }
        }
        return result;
    }

    private string ParseTime(int num)
    {
        int hour = num >> 6;
        int minut = num & 0x3F;

        if(hour > 11 || minut >59)
        {
            return "";
        }
        return hour.ToString() + ":"+ string.Format("{0:D2}", minut);
    }
    public List<string> readBinaryWatch(int num) {
        List<string> result = new List<string>();

        for(int i=0; i<12; i++){
            for(int j=0; j<60; j++){
                int total = countDigits(i)+countDigits(j);
                if(total==num){
                    string s="";
                    s+=i+":";

                    if(j<10){
                        s+="0"+j;
                    }else{
                        s+=j;
                    }

                    result.Add(s);
                }
            }
        }

        return result;
    }
    
    public int countDigits(int num){
        int result=0;
    
        while(num>0){
            if((num&1)==1){
                result++;
            }
    
            num>>=1;
        }
    
        return result;
    }
}