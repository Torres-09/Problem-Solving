select year(ym) YEAR, round(avg(PM_VAL1),2) PM10, round(avg(PM_VAL2),2) 'PM2.5'
from AIR_POLLUTION
where location2 = "수원"
group by year(ym)
order by YEAR