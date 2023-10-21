/* Write your T-SQL query statement below */
SELECT b.id FROM
Weather a, Weather b
WHERE DATEDIFF(day,a.recordDate,b.recordDate) = 1 AND b.temperature > a.temperature;