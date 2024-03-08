select name, count(animal_id) count
from animal_ins
group by name
having count(animal_id) > 1
   and name is not null
order by name;