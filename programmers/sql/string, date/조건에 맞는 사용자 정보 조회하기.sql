SELECT
    DISTINCT(A.USER_ID) USER_ID,
    A.NICKNAME,
    CONCAT(A.CITY, " ", A.STREET_ADDRESS1, " ", A.STREET_ADDRESS2) 전체주소, 
    CONCAT(SUBSTR(A.TLNO, 1, 3), "-", SUBSTR(A.TLNO, 4, 4), "-", SUBSTR(A.TLNO, 8, 4)) 전화번호
FROM USED_GOODS_USER A
RIGHT JOIN (
            SELECT WRITER_ID, COUNT(WRITER_ID) AS CNT
            FROM USED_GOODS_BOARD 
            GROUP BY WRITER_ID
            HAVING CNT >= 3
) B ON A.USER_ID = B.WRITER_ID
ORDER BY A.USER_ID DESC;