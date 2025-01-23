SELECT 
    Signups.user_id, 
    ROUND(
            COALESCE(
                AVG(
                    CASE 
                        WHEN action='confirmed' THEN 1 
                        ELSE 0 
                    END), 
                0), 
            2) 
    AS confirmation_rate
FROM Signups LEFT JOIN Confirmations
ON Signups.user_id = Confirmations.user_id
group by Signups.user_id
order by confirmation_rate ASC;

