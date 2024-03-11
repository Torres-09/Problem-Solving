SELECT distinct(crcc.car_id)
from CAR_RENTAL_COMPANY_CAR crcc
         join CAR_RENTAL_COMPANY_RENTAL_HISTORY  crcrh
              on crcc.car_id = crcrh.car_id
where crcc.car_type = "세단" and month(crcrh.start_date) = "10"
order by car_id desc