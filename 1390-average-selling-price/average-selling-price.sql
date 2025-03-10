# Write your MySQL query statement below
SELECT 
    p.product_id, 
    ROUND(
        COALESCE(
            SUM(p.price * u.units)/SUM(u.units), 
            0), 
        2) as average_price
FROM 
    Prices as p 
    LEFT JOIN UnitsSold as u
    ON p.product_id = u.product_id AND u.purchase_date between p.start_date and p.end_date
group by 
    p.product_id
order by 
    average_price ASC;