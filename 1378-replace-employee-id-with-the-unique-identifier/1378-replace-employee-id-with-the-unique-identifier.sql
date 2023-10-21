/* Write your T-SQL query statement below */
SELECT eu.unique_id as unique_id,e.name 
FROM Employees e 
LEFT JOIN  EmployeeUNI eu
ON eu.id = e.id;