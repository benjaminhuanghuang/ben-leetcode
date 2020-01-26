package cn.huang.leetcode;

/*
183. Customers Who Never Order

 */
public class LC_0183_CustomersWhoNeverOrder {
    /*
select c.Name as Customers
from Customers c
where not exists (select * from Orders o where o.customerId=c.id)
 */
}
