select animal_id, name
from animal_ins
where intake_condition != "aged"
order by animal_id;