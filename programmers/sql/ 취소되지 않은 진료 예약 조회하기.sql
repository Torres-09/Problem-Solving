SELECT a.apnt_no, p.pt_name, p.pt_no, a.mcdp_cd, d.dr_name, a.APNT_YMD
from appointment a
         join doctor d
              on a.MDDR_ID = d.DR_ID
         join patient p
              on p.pt_no = a.pt_no
where a.apnt_cncl_ymd is null and year(a.APNT_YMD) = 2022
  and month(a.APNT_YMD) = 04 and day(a.APNT_YMD) = 13
  and a.mcdp_cd = "CS"
order by APNT_YMD;