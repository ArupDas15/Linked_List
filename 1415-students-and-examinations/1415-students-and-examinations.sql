# Write your MySQL query statement below
SELECT stu.student_id, stu.student_name, sub.subject_name, COUNT(e.subject_name) AS attended_exams
FROM Students as stu
CROSS JOIN Subjects as sub
LEFT JOIN Examinations as e
ON stu.student_id = e.student_id AND sub.subject_name = e.subject_name
group by stu.student_id, sub.subject_name
order by stu.student_id ASC, sub.subject_name ASC;
