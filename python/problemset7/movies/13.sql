SELECT DISTINCT(people.name) FROM movies,stars,people WHERE movies.id=stars.movie_id AND people.id=stars.person_id AND movies.id IN (SELECT movies.id FROM movies,stars,people WHERE movies.id=stars.movie_id AND people.id=stars.person_id AND name='Kevin Bacon' AND birth=1958) AND NOT name = 'Kevin Bacon';