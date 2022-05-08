select distinct city
from station
where not (regexp_like(city, '^[aeiou]', 'i') and regexp_like(city, '[aeiou]$', 'i'));
