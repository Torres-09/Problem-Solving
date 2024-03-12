select concat("/home/grep/src/", b.board_id, "/", f.file_id, f.file_name, f.file_ext) FILE_PATH
from used_goods_board b
         join used_goods_file f
              on b.board_id = f.board_id
where b.views = (
    select max(views)
    from USED_GOODS_BOARD )
order by f.file_id desc