SELECT DISTINCT city
FROM station
WHERE REGEXP_LIKE(city, '^[aeiou]', 'i')
AND REGEXP_LIKE(city, '[aeiou]$', 'i');
