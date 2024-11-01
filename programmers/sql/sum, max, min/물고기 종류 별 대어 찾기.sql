SELECT D.ID, C.FISH_NAME, C.LENGTH
FROM FISH_INFO D
RIGHT JOIN (
    SELECT B.FISH_TYPE, B.FISH_NAME, MAX(LENGTH) LENGTH
    FROM FISH_INFO A
    LEFT JOIN FISH_NAME_INFO B ON A.FISH_TYPE = B.FISH_TYPE
    GROUP BY B.FISH_TYPE, B.FISH_NAME
) AS C ON D.FISH_TYPE = C.FISH_TYPE AND C.LENGTH = D.LENGTH
ORDER BY D.ID;