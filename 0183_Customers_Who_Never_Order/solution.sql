/*
183. Customers Who Never Order

https://leetcode.com/problems/customers-who-never-order/
 */

select c.Name as Customers
from Customers c
where not exists (select * from Orders o where o.customerId=c.id)

