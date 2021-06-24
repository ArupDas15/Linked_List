# Write your MySQL query statement below
SELECT MAX(Salary) as SecondHighestSalary FROM EMPLOYEE where Salary NOT IN (
SELECT MAX(Salary) FROM EMPLOYEE); 