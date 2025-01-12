# Write your MySQL query statement below
SELECT a.machine_id, ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
FROM Activity as a
JOIN Activity as b
ON a.machine_id = b.machine_id AND a.process_id = b.process_id
AND a.activity_type = 'start' and b.activity_type = 'end'
group by a.machine_id;
