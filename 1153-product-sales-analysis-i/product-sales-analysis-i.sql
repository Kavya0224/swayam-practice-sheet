# Write your MySQL query statement below
Select product_name,year,price
from sales s
join product p
on p.product_id=s.product_id;