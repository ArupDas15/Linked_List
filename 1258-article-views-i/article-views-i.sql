# Write your MySQL query statement below
SELECT 
    distinct(author_id) as id 
FROM 
    Views as v
where 
    v.author_id = v.viewer_id
order by 
    v.author_id ASC
;