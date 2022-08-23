--list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred
SELECT title
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE name = "Johnny Depp"
AND movie_id IN (
        SELECT movie_id
        FROM people JOIN stars ON stars.person_id = people.id
        WHERE name = "Helena Bonham Carter"
        );