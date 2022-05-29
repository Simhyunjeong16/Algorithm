SELECT city
FROM station
WHERE REGEXP_LIKE(city,'^[aeiou]', 'i');
