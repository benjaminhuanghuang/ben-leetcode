/*
   197. Rising Temperature
    https://leetcode.com/problems/rising-temperature/
*/
select a.ID from Weather a,Weather b where a.Temperature>b.Temperature and  DATEDIFF(a.RecordDate,b.RecordDate)=1
