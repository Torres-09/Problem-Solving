select name, datetime
from animal_ins
where animal_id not in (select ai.animal_id
                        from animal_ins ai
                                 join animal_outs ao
                                      on ai.animal_id = ao.animal_id)
order by datetime
limit 3