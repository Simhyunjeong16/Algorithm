SELECT A.AUTHOR_ID, C.AUTHOR_NAME, A.CATEGORY, SUM(B.SALES * A.PRICE) AS TOTAL_SALES
FROM BOOK A
INNER JOIN BOOK_SALES B ON A.BOOK_ID = B.BOOK_ID
INNER JOIN AUTHOR C ON A.AUTHOR_ID = C.AUTHOR_ID
WHERE B.SALES_DATE LIKE "2022-01%"
GROUP BY A.AUTHOR_ID, A.CATEGORY
ORDER BY A.AUTHOR_ID ASC, A.CATEGORY DESC;