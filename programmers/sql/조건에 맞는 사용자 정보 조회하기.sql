select user_id,
       nickname,
       concat(city, " ", STREET_ADDRESS1, " ", STREET_ADDRESS2)                              전체주소,
       concat(substring(tlno, 1, 3), "-", substring(tlno, 4, 4), "-", substring(tlno, 8, 4)) 전화번호
from USED_GOODS_USER
where user_id in (select writer_id
                  from USED_GOODS_BOARD
                  group by writer_id
                  having count(board_id) >= 3)
order by user_id desc