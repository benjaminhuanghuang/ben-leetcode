package cn.huang.leetcode;
/*
601. Human Traffic of Stadium

X city built a new stadium, each day many people visit it and the stats are saved as these columns: id, date, people

Please write a query to display the records which have 3 or more consecutive rows and the amount of people more than 100(inclusive).
For example, the table stadium:

+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+

 */
public class LC_0601_HumanTrafficofStadium {
    /*
        select id, date, people
         from (select id, date, people,
            case when consecutive >= 3 then @pending := 3
                 else @pending := @pending - 1
            end as tmp,
            if(@pending > 0, 1, 0) as include
         from (select id, date, people,
              case when people >= 100 then @count := @count + 1
                   else @count := 0
              end as consecutive
              from stadium, (select @count := 0) init1
        ) tmp, (select @pending := 0) init2
        order by 1 desc
        ) otmp where include = 1
        order by 1;
     */
}
