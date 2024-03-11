select ri.food_type, ri.rest_id, ri.rest_name, ri.FAVORITES
from rest_info ri
         join (
    select food_type, max(FAVORITES) max_FAVORITES
    from rest_info
    group by food_type
) rid
              on rid.food_type = ri.food_type and rid.max_FAVORITES = ri.FAVORITES
order by ri.food_type desc
