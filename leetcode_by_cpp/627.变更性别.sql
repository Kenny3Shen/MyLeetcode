# Write your MySQL query statement below

/* UPDATE salary SET sex = char(ASCII('m') ^ASCII('f') ^ ASCII(sex)); */

/* UPDATE salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END; */

UPDATE salary SET sex = IF(sex = 'm', 'f', 'm');