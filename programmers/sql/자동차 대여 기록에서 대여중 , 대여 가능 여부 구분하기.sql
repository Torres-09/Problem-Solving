select distinct a.car_id, case
                              when b.availability = "대여중" then b.availability
                              when b.availability is null then "대여 가능"
    end availability
from CAR_RENTAL_COMPANY_RENTAL_HISTORY a
         left join (
    select car_id, case
                       when start_date <= "2022-10-16" and end_date >= "2022-10-16" then "대여중"
        end AVAILABILITY
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    group by car_id, AVAILABILITY
    having AVAILABILITY is not null
) b
                   on a.car_id = b.car_id
order by car_id desc;

SELECT CAR_ID, (CASE
                    WHEN CAR_ID IN (
                        SELECT CAR_ID
                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                        WHERE '2022-10-16' BETWEEN DATE_FORMAT(START_DATE, '%Y-%m-%d') AND DATE_FORMAT(END_DATE, '%Y-%m-%d')
                    ) THEN '대여중'
                    ELSE '대여 가능'
    END) AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;