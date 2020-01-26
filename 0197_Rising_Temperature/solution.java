package cn.huang.leetcode;
/*
   197. Rising Temperature

    */
public class LC_0197_RisingTemperature {
    /*
select w1.Id from Weather w1, Weather w2 where w1.Temperature>w2.Temperature and TO_DAYS(w1.Date)-TO_DAYS(w2.Date)=1;

select a.ID from Weather a,Weather b where a.Temperature>b.Temperature and  DATEDIFF(a.RecordDate,b.RecordDate)=1

     */
}
