SELECT distinct A.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR A
INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY B
ON A.CAR_ID = B.CAR_ID
WHERE CAR_TYPE = "세단"
AND START_DATE like "%-10-%"
ORDER BY CAR_ID DESC;