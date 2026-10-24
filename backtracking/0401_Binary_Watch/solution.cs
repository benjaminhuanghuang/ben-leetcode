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