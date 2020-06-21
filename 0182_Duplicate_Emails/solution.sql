/*
182. Duplicate Emails

https://leetcode.com/problems/duplicate-emails/
 */

/*
方法1：
注意distinct用法  <>是不等于
*/

    select distinct(p.Email)
    from Person p, Person p1
    where (p.Id<>p1.Id and p.Email=p1.Email);

/*
#方法二：
注意group by重新分组的用法
*/
    select distinct p.Email
    from Person p
    group by p.Email
    having count(p.Email)>1;
