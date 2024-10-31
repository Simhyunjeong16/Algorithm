SELECT A.ITEM_ID, A.ITEM_NAME
FROM ITEM_INFO AS A
INNER JOIN (SELECT * FROM ITEM_TREE WHERE PARENT_ITEM_ID IS NULL) AS B
ON A.ITEM_ID = B.ITEM_ID
ORDER BY A.ITEM_ID;