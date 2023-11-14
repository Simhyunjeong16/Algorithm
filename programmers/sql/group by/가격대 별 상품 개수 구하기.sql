SELECT truncate(PRICE, -4) price_group, count(PRODUCT_ID) PRODUCTS
FROM PRODUCT
group by price_group
order by price_group;