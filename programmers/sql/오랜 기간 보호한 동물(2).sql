select ai.animal_id, ai.name
from animal_ins ai
         join animal_outs ao
              on ai.animal_id = ao.animal_id
order by datediff(ai.datetime, ao.datetime)
limit 2