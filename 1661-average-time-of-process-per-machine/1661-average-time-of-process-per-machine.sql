/* Write your T-SQL query statement below */
SELECT a.machine_id, ROUND((SUM(b.timestamp - a.timestamp)/COUNT(*)),3) AS processing_time
FROM Activity a 
JOIN Activity b 
ON a.process_id = b.process_id 
WHERE a.machine_id = b.machine_id AND b.activity_type = 'end' AND a.activity_type = 'start'
GROUP BY a.machine_id;