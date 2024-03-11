select ugu.user_id USER_ID, ugu.nickname NICKNAME, sum(price) TOTAL_SALES
from USED_GOODS_BOARD ugb
         join USED_GOODS_USER ugu
              on ugb.WRITER_ID = ugu.USER_ID
where ugb.STATUS = "DONE"
group by ugu.user_id
having total_sales >= 700000
order by total_sales
