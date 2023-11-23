SELECT concat("/home/grep/src/", BOARD_ID, "/", FILE_ID, FILE_NAME, FILE_EXT) as FILE_PATH
FROM USED_GOODS_FILE
where BOARD_ID = (select a.board_id from USED_GOODS_BOARD a order by a.views desc limit 1)
order by FILE_ID desc;