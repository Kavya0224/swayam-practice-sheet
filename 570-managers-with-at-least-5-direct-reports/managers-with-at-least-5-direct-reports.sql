# Write your MySQL query statement below
SELECT name
from Employee
where id in(
    SELECT managerId
    from Employee
    group by managerId
    having count(managerId)>=5
);