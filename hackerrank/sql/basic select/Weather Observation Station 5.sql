SELECT *
FROM (
SELECT CITY, length(CITY)
FROM STATION
ORDER BY length(CITY), CITY
)
WHERE ROWNUM <= 1;

SELECT *
FROM (
SELECT CITY, length(CITY)
FROM STATION
ORDER BY length(CITY) DESC, CITY
)
WHERE ROWNUM <= 1;
