SELECT name
  FROM people
  JOIN stars ON people.id = stars.person_id
  JOIN movies on stars.movie_id = movies.id
 WHERE movies.title = 'Toy Story';