#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:
    Movie(int movie_id);
    int getId() const;
private:
    int id;
};

#endif
